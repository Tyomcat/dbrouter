#ifndef _DBCOMMON_H
#define _DBCOMMON_H

#include <string.h>
#include <time.h>
#include <assert.h>
#include <spinlock.h>
#include <hashtable.h>

#define PARAM_RULE              "rules"
#define PARAM_LOG_MATCH         "log_match"
#define PARAM_LOG_NO_MATCH      "log_no_match"
#define PARAM_ACTION            "action"
#define PARAM_BLOCK             "block"
#define PARAM_IGNORE            "ignore"

/**
 * Logging options for matched queries
 */
#define FW_LOG_NONE         0x00
#define FW_LOG_MATCH        0x01
#define FW_LOG_NO_MATCH     0x02

/** Maximum length of the match/nomatch messages */
#define FW_MAX_SQL_LEN      400

#ifdef WIN32
    #define strcasecmp(A,B) _stricmp((A),(B))
#endif

#define CHK_TIMES(t) assert(t->tm_sec > -1 && t->tm_sec < 62        \
                                && t->tm_min > -1 && t->tm_min < 60     \
                                && t->tm_hour > -1 && t->tm_hour < 24)

#define IS_RVRS_TIME(tr) \(mktime(&tr->end) < mktime(&tr->start))

/* Useful macros used in several places */
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

/** Matching type */
enum match_type
{
    FWTOK_MATCH_ANY,
    FWTOK_MATCH_ALL,
    FWTOK_MATCH_STRICT_ALL
};

/**
 * Possible actions to take when the query matches a rule
 */
enum fw_actions
{
    FW_ACTION_ALLOW,
    FW_ACTION_BLOCK,
    FW_ACTION_IGNORE
};

typedef enum
{
    QUERY_OP_UNDEFINED     = 0,
    QUERY_OP_SELECT        = (1 << 0),
    QUERY_OP_UPDATE        = (1 << 1),
    QUERY_OP_INSERT        = (1 << 2),
    QUERY_OP_DELETE        = (1 << 3),
    QUERY_OP_TRUNCATE      = (1 << 4),
    QUERY_OP_ALTER         = (1 << 5),
    QUERY_OP_CREATE        = (1 << 6),
    QUERY_OP_DROP          = (1 << 7),
    QUERY_OP_CHANGE_DB     = (1 << 8),
    QUERY_OP_LOAD          = (1 << 9),
    QUERY_OP_GRANT         = (1 << 10),
    QUERY_OP_REVOKE        = (1 << 11)
} qc_query_op_t;

/**
 * Rule types
 */
typedef enum
{
    RT_UNDEFINED = 0x00, /*< Undefined rule */
    RT_COLUMN, /*<  Column name rule*/
    RT_THROTTLE, /*< Query speed rule */
    RT_PERMISSION, /*< Simple denying rule */
    RT_WILDCARD, /*< Wildcard denial rule */
    RT_REGEX, /*< Regex matching rule */
    RT_CLAUSE /*< WHERE-clause requirement rule */
} ruletype_t;

/**
 *  * Linked list of strings.
 *   */
typedef struct strlink_t
{
    struct strlink_t *next; /*< Next node in the list */
    char* value; /*< Value of the current node */
} STRLINK;

typedef struct user_template
{
    char *name;
    enum match_type type; /** Matching type */
    STRLINK *rulenames; /** names of the rules */
    struct user_template *next;
} user_template_t;

/**
 *  * A structure defining a range of time
 *   */
typedef struct timerange_t
{
    struct timerange_t* next; /*< Next node in the list */
    struct tm start; /*< Start of the time range */
    struct tm end; /*< End of the time range */
} TIMERANGE;

/**
 * A structure used to identify individual rules and to store their contents
 *
 * Each type of rule has different requirements that are expressed as void pointers.
 * This allows to match an arbitrary set of rules against a user.
 */
typedef struct rule_t
{
    void* data; /*< Actual implementation of the rule */
    char* name; /*< Name of the rule */
    ruletype_t type; /*< Type of the rule */
    qc_query_op_t on_queries; /*< Types of queries to inspect */
    bool allow; /*< Allow or deny the query if this rule matches */
    int times_matched; /*< Number of times this rule has been matched */
    TIMERANGE* active; /*< List of times when this rule is active */
    struct rule_t *next;
} RULE;

/**
 * Structure used to hold rules and users that are being parsed
 */
struct parser_stack
{
    RULE* rule;
    STRLINK* user;
    STRLINK* active_rules;
    enum match_type active_mode;
    user_template_t* templates;
};

/**
 * The structure used to pass name, value pairs to the filter instances
 */
typedef struct
{
    char    *name;          /**< Name of the parameter */
    char    *value;         /**< Value of the parameter */
} FILTER_PARAMETER;

/**
 * Query speed measurement and limitation structure
 */
typedef struct queryspeed_t
{
    time_t first_query; /*< Time when the first query occurred */
    time_t triggered; /*< Time when the limit was exceeded */
    int period; /*< Measurement interval in seconds */
    int cooldown; /*< Time the user is denied access for */
    int count; /*< Number of queries done */
    int limit; /*< Maximum number of queries */
    long id; /*< Unique id of the rule */
    bool active; /*< If the rule has been triggered */
    struct queryspeed_t* next; /*< Next node in the list */
} QUERYSPEED;

/**
 * Linked list of pointers to a global pool of RULE structs
 */
typedef struct rulelist_t
{
    RULE* rule; /*< The rule structure */
    struct rulelist_t* next; /*< Next node in the list */
} RULELIST;

typedef struct user_t
{
    char* name; /*< Name of the user */
    SPINLOCK lock; /*< User spinlock */
    QUERYSPEED* qs_limit; /*< The query speed structure unique to this user */
    RULELIST* rules_or; /*< If any of these rules match the action is triggered */
    RULELIST* rules_and; /*< All of these rules must match for the action to trigger */
    RULELIST* rules_strict_and; /*< rules that skip the rest of the rules if one of them
				 * fails. This is only for rules paired with 'match strict_all'. */

} USER;

typedef struct
{
    void* queue;
    char* user;
    char* remote_ip;
}SQL_FILTER_PARAMETER;

/**
 * Linked list of IP adresses and subnet masks
 */
typedef struct iprange_t
{
    struct iprange_t* next; /*< Next node in the list */
    unsigned int ip; /*< IP address */
    unsigned int mask; /*< Network mask */
} IPRANGE;

/**
 * The Firewall filter instance.
 */
typedef struct
{
    HASHTABLE* htable; /*< User hashtable */
    RULE* rules; /*< List of all the rules */
    STRLINK* userstrings; /*< Temporary list of raw strings of users */
    enum fw_actions action; /*< Default operation mode, defaults to deny */
    int log_match; /*< Log matching and/or non-matching queries */
    SPINLOCK lock; /*< Instance spinlock */
    int idgen; /*< UID generator */
} FW_INSTANCE;

#endif

