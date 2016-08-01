#ifndef _SQLITEINT_H_
#define _SQLITEINT_H_
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "sqliteLimit.h"
#include "hash.h"
#include "parse.h"

typedef long long sqlite_int64;
typedef unsigned long long sqlite_uint64;
typedef unsigned int UINT32_TYPE;
typedef short INT16_TYPE;
typedef unsigned short UINT16_TYPE;
typedef char INT8_TYPE;
typedef unsigned char UINT8_TYPE;

typedef sqlite_int64 i64;          /* 8-byte signed integer */
typedef sqlite_uint64 u64;         /* 8-byte unsigned integer */
typedef UINT32_TYPE u32;           /* 4-byte unsigned integer */
typedef UINT16_TYPE u16;           /* 2-byte unsigned integer */
typedef INT16_TYPE i16;            /* 2-byte signed integer */
typedef UINT8_TYPE u8;             /* 1-byte unsigned integer */
typedef INT8_TYPE i8;              /* 1-byte signed integer */

#if SQLITE_MAX_VARIABLE_NUMBER<=32767
typedef i16 ynVar;
#else
typedef int ynVar;
#endif

/*
** A sort order can be either ASC or DESC.
*/
#define SQLITE_SO_ASC       0  /* Sort in ascending order */
#define SQLITE_SO_DESC      1  /* Sort in ascending order */

/*
** Permitted values of the SrcList.a.jointype field
*/
#define JT_INNER     0x0001    /* Any kind of inner or cross join */
#define JT_CROSS     0x0002    /* Explicit use of the CROSS keyword */
#define JT_NATURAL   0x0004    /* True for a "natural" join */
#define JT_LEFT      0x0008    /* Left outer join */
#define JT_RIGHT     0x0010    /* Right outer join */
#define JT_OUTER     0x0020    /* The "OUTER" keyword is present */
#define JT_ERROR     0x0040    /* unknown or unsupported join type */

/*
** The following are the meanings of bits in the Expr.flags field.
*/
#define EP_FromJoin  0x000001 /* Originates in ON/USING clause of outer join */
#define EP_Agg       0x000002 /* Contains one or more aggregate functions */
#define EP_Resolved  0x000004 /* IDs have been resolved to COLUMNs */
#define EP_Error     0x000008 /* Expression contains one or more errors */
#define EP_Distinct  0x000010 /* Aggregate function with DISTINCT keyword */
#define EP_VarSelect 0x000020 /* pSelect is correlated, not constant */
#define EP_DblQuoted 0x000040 /* token.z was originally in "..." */
#define EP_InfixFunc 0x000080 /* True for an infix function: LIKE, GLOB, etc */
#define EP_Collate   0x000100 /* Tree contains a TK_COLLATE operator */
#define EP_Generic   0x000200 /* Ignore COLLATE or affinity on this tree */
#define EP_IntValue  0x000400 /* Integer value contained in u.iValue */
#define EP_xIsSelect 0x000800 /* x.pSelect is valid (otherwise x.pList is) */
#define EP_Skip      0x001000 /* COLLATE, AS, or UNLIKELY */
#define EP_Reduced   0x002000 /* Expr struct EXPR_REDUCEDSIZE bytes only */
#define EP_TokenOnly 0x004000 /* Expr struct EXPR_TOKENONLYSIZE bytes only */
#define EP_Static    0x008000 /* Held in memory not obtained from malloc() */
#define EP_MemToken  0x010000 /* Need to sqlite3DbFree() Expr.zToken */
#define EP_NoReduce  0x020000 /* Cannot EXPRDUP_REDUCE this Expr */
#define EP_Unlikely  0x040000 /* unlikely() or likelihood() function */
#define EP_ConstFunc 0x080000 /* Node is a SQLITE_FUNC_CONSTANT function */
#define EP_CanBeNull 0x100000 /* Can be null despite NOT NULL constraint */
#define EP_Subquery  0x200000 /* Tree contains a TK_SELECT operator */
#define EP_Propagate (EP_Collate|EP_Subquery) /* Propagate these bits up tree */

// Result Codes
#define SQLITE_OK           0   /* Successful result */
/* beginning-of-error-codes */
#define SQLITE_ERROR        1   /* SQL error or missing database */
#define SQLITE_INTERNAL     2   /* Internal logic error in SQLite */
#define SQLITE_PERM         3   /* Access permission denied */
#define SQLITE_ABORT        4   /* Callback routine requested an abort */
#define SQLITE_BUSY         5   /* The database file is locked */
#define SQLITE_LOCKED       6   /* A table in the database is locked */
#define SQLITE_NOMEM        7   /* A malloc() failed */
#define SQLITE_READONLY     8   /* Attempt to write a readonly database */
#define SQLITE_INTERRUPT    9   /* Operation terminated by sqlite3_interrupt()*/
#define SQLITE_IOERR       10   /* Some kind of disk I/O error occurred */
#define SQLITE_CORRUPT     11   /* The database disk image is malformed */
#define SQLITE_NOTFOUND    12   /* Unknown opcode in sqlite3_file_control() */
#define SQLITE_FULL        13   /* Insertion failed because database is full */
#define SQLITE_CANTOPEN    14   /* Unable to open the database file */
#define SQLITE_PROTOCOL    15   /* Database lock protocol error */
#define SQLITE_EMPTY       16   /* Database is empty */
#define SQLITE_SCHEMA      17   /* The database schema changed */
#define SQLITE_TOOBIG      18   /* String or BLOB exceeds size limit */
#define SQLITE_CONSTRAINT  19   /* Abort due to constraint violation */
#define SQLITE_MISMATCH    20   /* Data type mismatch */
#define SQLITE_MISUSE      21   /* Library used incorrectly */
#define SQLITE_NOLFS       22   /* Uses OS features not supported on host */
#define SQLITE_AUTH        23   /* Authorization denied */
#define SQLITE_FORMAT      24   /* Auxiliary database format error */
#define SQLITE_RANGE       25   /* 2nd parameter to sqlite3_bind out of range */
#define SQLITE_NOTADB      26   /* File opened that is not a database file */
#define SQLITE_NOTICE      27   /* Notifications from sqlite3_log() */
#define SQLITE_WARNING     28   /* Warnings from sqlite3_log() */
#define SQLITE_ROW         100  /* sqlite3_step() has another row ready */
#define SQLITE_DONE        101  /* sqlite3_step() has finished executing */

/*
** Size of the column cache
*/
#ifndef SQLITE_N_COLCACHE
# define SQLITE_N_COLCACHE 10
#endif

#ifndef SQLITE_PRINT_BUF_SIZE
# define SQLITE_PRINT_BUF_SIZE 70
#endif
#define etBUFSIZE SQLITE_PRINT_BUF_SIZE  /* Size of the output buffer */

typedef INT16_TYPE LogEst;
typedef u64 Bitmask;
#define BMS  ((int)(sizeof(Bitmask)*8))
#define MASKBIT(n)   (((Bitmask)1)<<(n))
#define MASKBIT32(n) (((unsigned int)1)<<(n))
#define Index void
#define FKey void
#define VTable void
#define Trigger void
#define With void
#define sqlite3 void
#define Vdbe void
#define AggInfo void
#define testcase(X)
#define sqlite3Malloc malloc
#define sqlite3_free free
#define UNUSED_PARAMETER(x) ((void) (x))
#define ALWAYS(X)      (X)
#define NEVER(X)       (X)

#if SQLITE_MAX_ATTACHED>30
  typedef unsigned char yDbMask[(SQLITE_MAX_ATTACHED+9)/8];
# define DbMaskTest(M,I)    (((M)[(I)/8]&(1<<((I)&7)))!=0)
# define DbMaskZero(M)      memset((M),0,sizeof(M))
# define DbMaskSet(M,I)     (M)[(I)/8]|=(1<<((I)&7))
# define DbMaskAllZero(M)   sqlite3DbMaskAllZero(M)
# define DbMaskNonZero(M)   (sqlite3DbMaskAllZero(M)==0)
#else
  typedef unsigned int yDbMask;
# define DbMaskTest(M,I)    (((M)&(((yDbMask)1)<<(I)))!=0)
# define DbMaskZero(M)      (M)=0
# define DbMaskSet(M,I)     (M)|=(((yDbMask)1)<<(I))
# define DbMaskAllZero(M)   (M)==0
# define DbMaskNonZero(M)   (M)!=0
#endif

# define sqlite3StackAllocRaw(N)   sqlite3DbMallocRaw(N)
# define sqlite3StackAllocZero(N)  sqlite3DbMallocZero(N)
# define sqlite3StackFree(P)       sqlite3DbFree(P)
# define sqlite3StrICmp            sqlite3_stricmp
# define sqlite3StrNICmp           sqlite3_strnicmp

#ifdef SQLITE_ASCII
# define sqlite3Toupper(x)        ((x)&~(sqlite3CtypeMap[(unsigned char)(x)]&0x20))
# define sqlite3Isspace(x)        (sqlite3CtypeMap[(unsigned char)(x)]&0x01)
# define sqlite3Isalnum(x)        (sqlite3CtypeMap[(unsigned char)(x)]&0x06)
# define sqlite3Isalpha(x)        (sqlite3CtypeMap[(unsigned char)(x)]&0x02)
# define sqlite3Isdigit(x)        (sqlite3CtypeMap[(unsigned char)(x)]&0x04)
# define sqlite3Isxdigit(x)       (sqlite3CtypeMap[(unsigned char)(x)]&0x08)
# define sqlite3Tolower(x)        (sqlite3UpperToLower[(unsigned char)(x)])
#else
# define sqlite3Toupper(x)        toupper((unsigned char)(x))
# define sqlite3Isspace(x)        isspace((unsigned char)(x))
# define sqlite3Isalnum(x)        isalnum((unsigned char)(x))
# define sqlite3Isalpha(x)        isalpha((unsigned char)(x))
# define sqlite3Isdigit(x)        isdigit((unsigned char)(x))
# define sqlite3Isxdigit(x)       isxdigit((unsigned char)(x))
# define sqlite3Tolower(x)        tolower((unsigned char)(x))
#endif

// Expr property
#define ExprHasProperty(E,P)     (((E)->flags&(P))!=0)
#define ExprHasAllProperty(E,P)  (((E)->flags&(P))==(P))
#define ExprSetProperty(E,P)     (E)->flags|=(P)
#define ExprClearProperty(E,P)   (E)->flags&=~(P)

/*
** SQLite supports many different ways to resolve a constraint
** error.  ROLLBACK processing means that a constraint violation
** causes the operation in process to fail and for the current transaction
** to be rolled back.  ABORT processing means the operation in process
** fails and any prior changes from that one operation are backed out,
** but the transaction is not rolled back.  FAIL processing means that
** the operation in progress stops and returns an error code.  But prior
** changes due to the same operation are not backed out and no rollback
** occurs.  IGNORE means that the particular row that caused the constraint
** error is not inserted or updated.  Processing continues and no error
** is returned.  REPLACE means that preexisting database rows that caused
** a UNIQUE constraint violation are removed so that the new insert or
** update can proceed.  Processing continues and no error is reported.
**
** RESTRICT, SETNULL, and CASCADE actions apply only to foreign keys.
** RESTRICT is the same as ABORT for IMMEDIATE foreign keys and the
** same as ROLLBACK for DEFERRED keys.  SETNULL means that the foreign
** key is set to NULL.  CASCADE means that a DELETE or UPDATE of the
** referenced table row is propagated into the row that holds the
** foreign key.
** 
** The following symbolic values are used to record which type
** of action to take.
*/
#define OE_None     0   /* There is no constraint to check */
#define OE_Rollback 1   /* Fail the operation and rollback the transaction */
#define OE_Abort    2   /* Back out changes but do no rollback transaction */
#define OE_Fail     3   /* Stop the operation but leave all prior changes */
#define OE_Ignore   4   /* Ignore the error. Do not do the INSERT or UPDATE */
#define OE_Replace  5   /* Delete existing record, then do INSERT or UPDATE */

#define OE_Restrict 6   /* OE_Abort for IMMEDIATE, OE_Rollback for DEFERRED */
#define OE_SetNull  7   /* Set the foreign key value to NULL */
#define OE_SetDflt  8   /* Set the foreign key value to its default */
#define OE_Cascade  9   /* Cascade the changes */

#define OE_Default  10  /* Do whatever the default action is */

/*
** Allowed values for Select.selFlags.  The "SF" prefix stands for
** "Select Flag".
*/
#define SF_Distinct        0x0001  /* Output should be DISTINCT */
#define SF_All             0x0002  /* Includes the ALL keyword */
#define SF_Resolved        0x0004  /* Identifiers have been resolved */
#define SF_Aggregate       0x0008  /* Contains aggregate functions */
#define SF_UsesEphemeral   0x0010  /* Uses the OpenEphemeral opcode */
#define SF_Expanded        0x0020  /* sqlite3SelectExpand() called on this */
#define SF_HasTypeInfo     0x0040  /* FROM subqueries have Table metadata */
#define SF_Compound        0x0080  /* Part of a compound query */
#define SF_Values          0x0100  /* Synthesized from VALUES clause */
#define SF_MultiValue      0x0200  /* Single VALUES term with multiple rows */
#define SF_NestedFrom      0x0400  /* Part of a parenthesized FROM clause */
#define SF_MaybeConvert    0x0800  /* Need convertCompoundSelectToSubquery() */
#define SF_MinMaxAgg       0x1000  /* Aggregate containing min() or max() */
#define SF_Recursive       0x2000  /* The recursive part of a recursive CTE */
#define SF_Converted       0x4000  /* By convertCompoundSelectToSubquery() */
#define SF_SpecialSelect   0x8000  /* special select,select @@ or select function*/


/*show commond*/
#define SHOW_DATABASES    0
#define SHOW_TABLES       1
#define SHOW_VARIABLES    2
#define SHOW_COLUMNS      3
#define SHOW_STATUS       4
#define SHOW_CREATE_TABLE 5
#define SHOW_COLLATION    6
#define SHOW_WARNINGS     7
#define SHOW_ENGINES      8

/*show status type*/
#define SHOW_STATUS_FUNCTION  1
#define SHOW_STATUS_PROCEDURE 2
#define SHOW_STATUS_PROXY     3

/*set range*/
#define RANGE_SESSION 1
#define RANGE_GLOBAL  2
#define RANGE_LOCAL   3

/*set param*/
#define SEQ_SCAN                1
#define ENCODE_NAMES            2
#define TRANSACTION_SET         3
#define PROCESSTIMEOUT_SET      4
#define CHARACTER_SET_SET       5
#define SQL_MODE_SET            6
#define AUTOCOMMIT_SET          7
#define SQL_SAFE_UPDATES        8
#define INTERACTIVE_TIMEOUT_SET 9
#define IGNORESHARDINGERROR_SET 10
#define CHARSET_RESULT          11

#define SET_READ_UNCOMMITTED 1
#define SET_READ_COMMITTED 2
#define SET_REPEATABLE_READ 3
#define SET_SERIALIZABLE 4

/*txn type*/
#define TXN_BEGIN     1
#define TXN_COMMIT    2
#define TXN_ROLLBACK  3

/*force opt*/
#define FORCE_ALL      0
#define FORCE_MASTER   1
#define FORCE_PORTION  2

static const unsigned char sqlite3UpperToLower[] = {
      0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17,
     18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
     36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53,
     54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 97, 98, 99,100,101,102,103,
    104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,
    122, 91, 92, 93, 94, 95, 96, 97, 98, 99,100,101,102,103,104,105,106,107,
    108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,
    126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
    144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,
    162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,
    180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,
    198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,
    216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,
    234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,
    252,253,254,255
};

static const unsigned char sqlite3CtypeMap[256] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  /* 00..07    ........ */
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,  /* 08..0f    ........ */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  /* 10..17    ........ */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  /* 18..1f    ........ */
  0x01, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,  /* 20..27     !"#$%&' */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  /* 28..2f    ()*+,-./ */
  0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,  /* 30..37    01234567 */
  0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  /* 38..3f    89:;<=>? */

  0x00, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x02,  /* 40..47    @ABCDEFG */
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,  /* 48..4f    HIJKLMNO */
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,  /* 50..57    PQRSTUVW */
  0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x40,  /* 58..5f    XYZ[\]^_ */
  0x00, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x22,  /* 60..67    `abcdefg */
  0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,  /* 68..6f    hijklmno */
  0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,  /* 70..77    pqrstuvw */
  0x22, 0x22, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00,  /* 78..7f    xyz{|}~. */

  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* 80..87    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* 88..8f    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* 90..97    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* 98..9f    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* a0..a7    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* a8..af    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* b0..b7    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* b8..bf    ........ */

  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* c0..c7    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* c8..cf    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* d0..d7    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* d8..df    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* e0..e7    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* e8..ef    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  /* f0..f7    ........ */
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40   /* f8..ff    ........ */
};

typedef struct Token Token;
typedef struct ExprList ExprList;
typedef struct Expr Expr;
typedef struct SelectDest SelectDest;
typedef struct Select Select;
typedef struct Delete Delete;
typedef struct Update Update;
typedef struct Insert Insert;
typedef struct FullTable FullTable;
typedef struct SrcList SrcList;
typedef struct Schema Schema;
typedef struct Table Table;
typedef struct IdList IdList;
typedef struct Column Column;
typedef struct ExprSpan ExprSpan;
typedef struct Parse Parse;
typedef struct Show Show;
typedef struct Set Set;
typedef struct Use Use;
typedef struct TxnCmd TxnCmd;

struct Token {
  const char *z;     /* Text of the token.  Not NULL-terminated! */
  unsigned int n;    /* Number of characters in this token */
};

static const Token sqlite3IntTokens[] = {
   { "0", 1 },
   { "1", 1 }
};

struct ExprList {
  int nExpr;             /* Number of expressions on the list */
  struct ExprList_item { /* For each expression in the list */
    Expr *pExpr;            /* The list of expressions */
    char *zName;            /* Token associated with this expression */
    char *zSpan;            /* Original text of the expression */
    u8 sortOrder;           /* 1 for DESC or 0 for ASC */
    unsigned done :1;       /* [X] A flag to indicate when processing is finished */
    unsigned bSpanIsTab :1; /* [X] zSpan holds DB.TABLE.COLUMN */
    unsigned reusable :1;   /* [X] Constant expression is reusable */
    union {
      struct {
        u16 iOrderByCol;      /* [X] For ORDER BY, column number in result set */
        u16 iAlias;           /* [X] Index into Parse.aAlias[] for zName */
      } x;                    /* [X] */
      int iConstExprReg;      /* [X] Register in which Expr value is cached */
    } u;                      /* [X] */
  } *a;                  /* Alloc a power of two greater or equal to nExpr */
};


/*
** Each node of an expression in the parse tree is an instance
** of this structure.
**
** Expr.op is the opcode. The integer parser token codes are reused
** as opcodes here. For example, the parser defines TK_GE to be an integer
** code representing the ">=" operator. This same integer code is reused
** to represent the greater-than-or-equal-to operator in the expression
** tree.
**
** If the expression is an SQL literal (TK_INTEGER, TK_FLOAT, TK_BLOB, 
** or TK_STRING), then Expr.token contains the text of the SQL literal. If
** the expression is a variable (TK_VARIABLE), then Expr.token contains the 
** variable name. Finally, if the expression is an SQL function (TK_FUNCTION),
** then Expr.token contains the name of the function.
**
** Expr.pRight and Expr.pLeft are the left and right subexpressions of a
** binary operator. Either or both may be NULL.
**
** Expr.x.pList is a list of arguments if the expression is an SQL function,
** a CASE expression or an IN expression of the form "<lhs> IN (<y>, <z>...)".
** Expr.x.pSelect is used if the expression is a sub-select or an expression of
** the form "<lhs> IN (SELECT ...)". If the EP_xIsSelect bit is set in the
** Expr.flags mask, then Expr.x.pSelect is valid. Otherwise, Expr.x.pList is 
** valid.
**
** An expression of the form ID or ID.ID refers to a column in a table.
** For such expressions, Expr.op is set to TK_COLUMN and Expr.iTable is
** the integer cursor number of a VDBE cursor pointing to that table and
** Expr.iColumn is the column number for the specific column.  If the
** expression is used as a result in an aggregate SELECT, then the
** value is also stored in the Expr.iAgg column in the aggregate so that
** it can be accessed after all aggregates are computed.
**
** If the expression is an unbound variable marker (a question mark 
** character '?' in the original SQL) then the Expr.iTable holds the index 
** number for that variable.
**
** If the expression is a subquery then Expr.iColumn holds an integer
** register number containing the result of the subquery.  If the
** subquery gives a constant result, then iTable is -1.  If the subquery
** gives a different answer at different times during statement processing
** then iTable is the address of a subroutine that computes the subquery.
**
** If the Expr is of type OP_Column, and the table it is selecting from
** is a disk table or the "old.*" pseudo-table, then pTab points to the
** corresponding table definition.
**
** ALLOCATION NOTES:
**
** Expr objects can use a lot of memory space in database schema.  To
** help reduce memory requirements, sometimes an Expr object will be
** truncated.  And to reduce the number of memory allocations, sometimes
** two or more Expr objects will be stored in a single memory allocation,
** together with Expr.zToken strings.
**
** If the EP_Reduced and EP_TokenOnly flags are set when
** an Expr object is truncated.  When EP_Reduced is set, then all
** the child Expr objects in the Expr.pLeft and Expr.pRight subtrees
** are contained within the same memory allocation.  Note, however, that
** the subtrees in Expr.x.pList or Expr.x.pSelect are always separately
** allocated, regardless of whether or not EP_Reduced is set.
*/
struct Expr {
  u8 op;                 /* Operation performed by this node */
  char affinity;         /* [X] The affinity of the column or 0 if not a column */
  u32 flags;             /* Various flags.  EP_* See below */
  union {
    char *zToken;          /* Token value. Zero terminated and dequoted, including float */
    //int iValue;          /* Non-negative integer value if EP_IntValue */
	sqlite_int64 iValue;   /* Support bigInt - long long data type */	
  } u;

  /* If the EP_TokenOnly flag is set in the Expr.flags mask, then no
  ** space is allocated for the fields below this point. An attempt to
  ** access them will result in a segfault or malfunction. 
  *********************************************************************/

  Expr *pLeft;           /* Left subnode */
  Expr *pRight;          /* Right subnode */
  union {
    ExprList *pList;     /* op = IN, EXISTS, SELECT, CASE, FUNCTION, BETWEEN */
    Select *pSelect;     /* EP_xIsSelect and op = IN, EXISTS, SELECT */
  } x;

  /* If the EP_Reduced flag is set in the Expr.flags mask, then no
  ** space is allocated for the fields below this point. An attempt to
  ** access them will result in a segfault or malfunction.
  *********************************************************************/

#if SQLITE_MAX_EXPR_DEPTH>0
  int nHeight;           /* Height of the tree headed by this node */
#endif
  int iTable;            /* TK_COLUMN: cursor number of table holding column
                         ** TK_REGISTER: register number
                         ** TK_TRIGGER: 1 -> new, 0 -> old
                         ** EP_Unlikely:  134217728 times likelihood */
  ynVar iColumn;         /* TK_COLUMN: column index.  -1 for rowid.
                         ** TK_VARIABLE: variable number (always >= 1). */
  i16 iAgg;              /* Which entry in pAggInfo->aCol[] or ->aFunc[] */
  i16 iRightJoinTable;   /* If EP_FromJoin, the right table of the join */
  u8 op2;                /* TK_REGISTER: original value of Expr.op
                         ** TK_COLUMN: the value of p5 for OP_Column
                         ** TK_AGG_FUNCTION: nesting depth */
  AggInfo *pAggInfo;     /* Used by TK_AGG_COLUMN and TK_AGG_FUNCTION */
  Table *pTab;           /* Table for TK_COLUMN expressions. */
};

struct SelectDest {
  u8 eDest;            /* How to dispose of the results.  On of SRT_* above. */
  char affSdst;        /* Affinity used when eDest==SRT_Set */
  int iSDParm;         /* A parameter used by the eDest disposal method */
  int iSdst;           /* Base register where results are written */
  int nSdst;           /* Number of registers allocated */
  ExprList *pOrderBy;  /* Key columns for SRT_Queue and SRT_DistQueue */
};

struct Select {
  ExprList *pEList;      /* The fields of the result */
  u8 op;                 /* One of: TK_UNION TK_ALL TK_INTERSECT TK_EXCEPT */
  u16 selFlags;          /* Various SF_* values */
  int iLimit, iOffset;   /* Memory registers holding LIMIT & OFFSET counters */
  int addrOpenEphm[2];   /* OP_OpenEphem opcodes related to this select */
  u64 nSelectRow;        /* Estimated number of result rows */
  SrcList *pSrc;         /* The FROM clause */
  Expr *pWhere;          /* The WHERE clause */
  ExprList *pGroupBy;    /* The GROUP BY clause */
  Expr *pHaving;         /* The HAVING clause */
  ExprList *pOrderBy;    /* The ORDER BY clause */
  Select *pPrior;        /* Prior select in a compound select statement */
  Select *pNext;         /* Next select to the left in a compound */
  Expr *pLimit;          /* LIMIT expression. NULL means not used. */
  Expr *pOffset;         /* OFFSET expression. NULL means not used. */
  With *pWith;           /* WITH clause attached to this select. Or NULL. */
  ExprList *pForce;
  ExprList *pSpc;
};

struct Delete {
  SrcList *pSrc;         /* The FROM clause */
  Expr *pWhere;          /* The WHERE clause */
  ExprList *pOrderBy;    /* The ORDER BY clause */
  Expr *pLimit;          /* LIMIT expression. NULL means not used. */
  Expr *pOffset;         /* OFFSET expression. NULL means not used. */
  ExprList *pForce;
};

struct Update {
  ExprList *pSetList;    /* The SET clause */
  SrcList *pSrc;         /* Table */
  Expr *pWhere;          /* The WHERE clause */
  ExprList *pOrderBy;    /* The ORDER BY clause */
  Expr *pLimit;          /* LIMIT expression. NULL means not used. */
  Expr *pOffset;         /* OFFSET expression. NULL means not used. */
  ExprList *pForce;
};

struct Insert {
  SrcList *pSrc;         /* Table */
  IdList *pColumn;       /* The column */
  Select *pSelect;       /* The values, NULL: default value */
  int onError;           /* Reserved */
  ExprList *pForce;
};

struct FullTable {
  Token database;    /* Name of database holding this table */
  Token schema;      /* Name of the schema (for mssql only) */
  Token table;       /* Name of the table */
};

struct SrcList {
  int nSrc;        /* Number of tables or subqueries in the FROM clause */
  u32 nAlloc;      /* Number of entries allocated in a[] below */
  struct SrcList_item {
    Schema *pSchema;  /* [X] Schema to which this item is fixed */
    char *zDatabase;  /* Name of database holding this table */
    char *zSchema;    /* Name of the schema (for mssql only) */
    char *zName;      /* Name of the table */
    char *zAlias;     /* The "B" part of a "A AS B" phrase.  zName is the "A" */
    Table *pTab;      /* [X] An SQL table corresponding to zName */
    Select *pSelect;  /* [X:SQLITE_OMIT_SUBQUERY] A SELECT statement used in place of a table name */
    int addrFillSub;  /* [X] Address of subroutine to manifest a subquery */
    int regReturn;    /* [X] Register holding return address of addrFillSub */
    int regResult;    /* [X] Registers holding results of a co-routine */
    u8 jointype;      /* Type of join between this able and the previous */
	int iLock;        /* support MSSQL sytanx,1-NOLOCK,2-LOCK*/
    unsigned notIndexed :1;    /* [X] True if there is a NOT INDEXED clause */
    unsigned isCorrelated :1;  /* [X] True if sub-query is correlated */
    unsigned viaCoroutine :1;  /* [X] Implemented as a co-routine */
    unsigned isRecursive :1;   /* [X] True for recursive reference in WITH */
#ifndef SQLITE_OMIT_EXPLAIN
    u8 iSelectId;     /* [X] If pSelect!=0, the id of the sub-select in EQP */
#endif
    int iCursor;      /* [X] The VDBE cursor number used to access this table */
    Expr *pOn;        /* The ON clause of a join */
    IdList *pUsing;   /* The USING clause of a join */
    Bitmask colUsed;  /* [X] Bit N (1<<N) set if column N of pTab is used */
    char *zIndexedBy; /* [X] Identifier from "INDEXED BY <zIndex>" clause */
    Index *pIndex;    /* [X] Index structure corresponding to zIndex, if any */
  } a[1];             /* One entry for each identifier on the list */
};

struct Schema {
  int schema_cookie;   /* Database schema version number for this file */
  int iGeneration;     /* Generation counter.  Incremented with each change */
  Hash tblHash;        /* All tables indexed by name */
  Hash idxHash;        /* All (named) indices indexed by name */
  Hash trigHash;       /* All triggers indexed by name */
  Hash fkeyHash;       /* All foreign keys by referenced table name */
  Table *pSeqTab;      /* The sqlite_sequence table used by AUTOINCREMENT */
  u8 file_format;      /* Schema format version for this file */
  u8 enc;              /* Text encoding used by this database */
  u16 schemaFlags;     /* Flags associated with this schema */
  int cache_size;      /* Number of pages to use in the cache */
};

struct Table {
  char *zName;         /* Name of the table or view */
  Column *aCol;        /* Information about each column */
  Index *pIndex;       /* List of SQL indexes on this table. */
  Select *pSelect;     /* NULL for tables.  Points to definition if a view. */
  FKey *pFKey;         /* Linked list of all foreign keys in this table */
  char *zColAff;       /* String defining the affinity of each column */
  int tnum;            /* Root BTree page for this table */
  i16 iPKey;           /* If not negative, use aCol[iPKey] as the rowid */
  i16 nCol;            /* Number of columns in this table */
  u16 nRef;            /* Number of pointers to this Table */
  LogEst nRowLogEst;   /* Estimated rows in table - from sqlite_stat1 table */
  LogEst szTabRow;     /* Estimated size of each table row in bytes */
  u8 tabFlags;         /* Mask of TF_* values */
  u8 keyConf;          /* What to do in case of uniqueness conflict on iPKey */
  Trigger *pTrigger;   /* List of triggers stored in pSchema */
  Schema *pSchema;     /* Schema that contains this table */
  Table *pNextZombie;  /* Next on the Parse.pZombieTab list */
};

struct IdList {
  struct IdList_item {
    char *zName;      /* Name of the identifier */
    int idx;          /* Index in some Table.aCol[] of a column named zName */
  } *a;
  int nId;         /* Number of identifiers on the list */
};

struct Column {
  char *zName;     /* Name of this column */
  Expr *pDflt;     /* Default value of this column */
  char *zDflt;     /* Original text of the default value */
  char *zType;     /* Data type for this column */
  char *zColl;     /* Collating sequence.  If NULL, use the default */
  u8 notNull;      /* An OE_ code for handling a NOT NULL constraint */
  char affinity;   /* One of the SQLITE_AFF_... values */
  u8 szEst;        /* Estimated size of this column.  INT==1 */
  u8 colFlags;     /* Boolean properties.  See COLFLAG_ defines below */
};

struct ExprSpan {
  Expr *pExpr;          /* The expression parse tree */
  const char *zStart;   /* First character of input text */
  const char *zEnd;     /* One character past the end of input text */
};

struct Show {
	int iOP;
	int iFlags;
	int iOP2;
	IdList *pList;
	Expr *pExpr;
	Token *pToken;
	Expr *pWild;
	Expr *pLimit;
	Expr *pOffset;
};

struct Set {
	ExprList *opList;
	int iParam;
	int iClause;
};

struct Use {
	Token database;
};

struct TxnCmd {
	int iType;
	int iWork;
};

struct Parse {
  //sqlite3 *db;         /* The main database structure */
  char *zErrMsg;       /* An error message */
  //Vdbe *pVdbe;         /* An engine for executing database bytecode */
  int rc;              /* Return code from execution */
  u8 colNamesSet;      /* TRUE after OP_ColumnName has been issued to pVdbe */
  u8 checkSchema;      /* Causes schema cookie check after an error */
  u8 nested;           /* Number of nested calls to the parser/code generator */
  u8 nTempReg;         /* Number of temporary registers in aTempReg[] */
  u8 isMultiWrite;     /* True if statement may modify/insert multiple rows */
  u8 mayAbort;         /* True if statement may throw an ABORT exception */
  u8 hasCompound;      /* Need to invoke convertCompoundSelectToSubquery() */
  u8 okConstFactor;    /* OK to factor out constants */
  int aTempReg[8];     /* Holding area for temporary registers */
  int nRangeReg;       /* Size of the temporary register block */
  int iRangeReg;       /* First register in temporary register block */
  int nErr;            /* Number of errors seen */
  int nTab;            /* Number of previously allocated VDBE cursors */
  int nMem;            /* Number of memory cells used so far */
  int nSet;            /* Number of sets used so far */
  int nOnce;           /* Number of OP_Once instructions so far */
  int nOpAlloc;        /* Number of slots allocated for Vdbe.aOp[] */
  int iFixedOp;        /* Never back out opcodes iFixedOp-1 or earlier */
  int ckBase;          /* Base register of data during check constraints */
  int iPartIdxTab;     /* Table corresponding to a partial index */
  int iCacheLevel;     /* ColCache valid when aColCache[].iLevel<=iCacheLevel */
  int iCacheCnt;       /* Counter used to generate aColCache[].lru values */
  int nLabel;          /* Number of labels used */
  int *aLabel;         /* Space to hold the labels */
  struct yColCache {
    int iTable;           /* Table cursor number */
    i16 iColumn;          /* Table column number */
    u8 tempReg;           /* iReg is a temp register that needs to be freed */
    int iLevel;           /* Nesting level */
    int iReg;             /* Reg with value of this column. 0 means none. */
    int lru;              /* Least recently used entry has the smallest value */
  } aColCache[SQLITE_N_COLCACHE];  /* One for each column cache entry */
  ExprList *pConstExpr;/* Constant expressions */
  Token constraintName;/* Name of the constraint currently being parsed */
  yDbMask writeMask;   /* Start a write transaction on these databases */
  yDbMask cookieMask;  /* Bitmask of schema verified databases */
  int cookieValue[SQLITE_MAX_ATTACHED+2];  /* Values of cookies to verify */
  int regRowid;        /* Register holding rowid of CREATE TABLE entry */
  int regRoot;         /* Register holding root page number for new objects */
  int nMaxArg;         /* Max args passed to user function by sub-program */
  //AutoincInfo *pAinc;  /* Information about AUTOINCREMENT counters */

  /************************************************************************
  ** Above is constant between recursions.  Below is reset before and after
  ** each recursion.  The boundary between these two regions is determined
  ** using offsetof(Parse,nVar) so the nVar field must be the first field
  ** in the recursive region.
  ************************************************************************/

  int nVar;                 /* Number of '?' variables seen in the SQL so far */
  int nzVar;                /* Number of available slots in azVar[] */
  u8 iPkSortOrder;          /* ASC or DESC for INTEGER PRIMARY KEY */
  u8 bFreeWith;             /* True if pWith should be freed with parser */
  u8 explain;               /* True if the EXPLAIN flag is found on the query */
  int nAlias;               /* Number of aliased result set columns */
  int nHeight;              /* Expression tree height of current sub-select */
  char **azVar;             /* Pointers to names of parameters */
  Vdbe *pReprepare;         /* VM being reprepared (sqlite3Reprepare()) */
  const char *zTail;        /* All SQL text past the last semicolon parsed */
  //Table *pNewTable;         /* A table being constructed by CREATE TABLE */
  //Trigger *pNewTrigger;     /* Trigger under construct by a CREATE TRIGGER */
  //const char *zAuthContext; /* The 6th parameter to db->xAuth callbacks */
  Token sNameToken;         /* Token with unqualified schema object name */
  Token sLastToken;         /* The last token parsed */
  //Table *pZombieTab;        /* List of Table objects to delete after code gen */
  //TriggerPrg *pTriggerPrg;  /* Linked list of coded triggers */
  //With *pWith;              /* Current WITH clause, or NULL */
  
  
  /************************************************************************
  ** Below is the result of parser (AST)
  ************************************************************************/
  Select *pSelectRes;
  Delete *pDeleteRes;
  Update *pUpdateRes;
  Insert *pInsertRes;
  Show *pShowRes;
  Set *pSetRes;
  Use *pUseRes;
  TxnCmd *pTxnCmdRes;
};

// function
void sqlite3ErrorMsg(Parse *pParse, const char *zFormat, ...);
void sqlite3ErrorMsgT(Parse *pParse, const char *zFormat, Token *pT);
void sqlite3BeginParse(Parse *pParse, int explainFlag);
void sqlite3FinishCoding(Parse *pParse);
void sqlite3Delete(Parse *pParse, FullTable *pTable, Expr *pWhere, ExprList *pOrderBy, Expr *pLimit, Expr *pOffset, ExprList *pForce);
void sqlite3Update(Parse *pParse, FullTable *pTable, ExprList *pSetList, Expr *pWhere, ExprList *pOrderBy, Expr *pLimit, Expr *pOffset, ExprList *pForce);
void sqlite3Insert(Parse *pParse, FullTable *pTable, Select *pSelect, IdList *pColumn, int onError, ExprList *pForce);
int  sqlite3Select(Parse *pParse, Select *p);
void sqlite3SelectDelete(Select *p);
void sqlite3DeleteDelete(Delete *p);
void sqlite3UpdateDelete(Update *p);
void sqlite3InsertDelete(Insert *p);
void sqlite3UseDatabaseDelete(Use *p);
void sqlite3ShowDelete(Show *p);
void sqlite3SetDelete(Set *p);
void sqlite3ExprListDelete(ExprList *p);
void sqlite3FullTableDelete(FullTable *p);
void sqlite3SrcListDelete(SrcList *p);
void sqlite3ExprDelete(Expr *p);
void sqlite3WithDelete(With *p);
void sqlite3IdListDelete(IdList *pList);
void *sqlite3DbMallocRaw(unsigned int n);
void *sqlite3DbMallocZero(unsigned int iSize);
void *sqlite3DbRealloc(void *p, u64 n);
void sqlite3DbFree(void *p);
int  sqlite3Strlen30(const char *z);
char *sqlite3DbStrNDup(const char *z, u64 n);
Select *sqlite3SelectNew(Parse *pParse, ExprList *pEList, SrcList *pSrc, Expr *pWhere, ExprList *pGroupBy, Expr *pHaving, ExprList *pOrderBy, u16 selFlags, Expr *pLimit, Expr *pOffset, ExprList *pForce, ExprList *pSpc);
ExprList *sqlite3ExprListAppend(Parse *pParse, ExprList *pList, Expr *pExpr);
void sqlite3ExprListSetName(Parse *pParse, ExprList *pList, Token *pName, int dequote);
void sqlite3ExprListSetSpan(Parse *pParse, ExprList *pList, ExprSpan *pSpan);
Expr *sqlite3Expr(Parse *pParse, int op, const char *zToken);
Expr *sqlite3ExprAlloc(int op, const Token *pToken, int dequote);
int  sqlite3Dequote(char *z);
Expr *sqlite3PExpr(Parse *pParse, int op, Expr *pLeft, Expr *pRight, const Token *pToken);
Expr *sqlite3ExprAnd(Expr *pLeft, Expr *pRight);
void sqlite3ExprAttachSubtrees(Expr *pRoot, Expr *pLeft, Expr *pRight);
int  sqlite3ExprCheckHeight(Parse *pParse, int nHeight);
void exprSetHeight(Expr *p);
sqlite_int64 sqlite3ExprIsInteger(Expr *p, sqlite_int64 *pValue);
void heightOfExpr(Expr *p, int *pnHeight);
void heightOfExprList(ExprList *p, int *pnHeight);
void heightOfSelect(Select *p, int *pnHeight);
u32  sqlite3ExprListFlags(const ExprList *pList);
void sqlite3SrcListShiftJoinType(SrcList *p);
SrcList *sqlite3SrcListAppendFromTerm(Parse *pParse, SrcList *p, Token *pTable, Token *pSchema, Token *pDatabase, Token *pAlias, Select *pSubquery, Expr *pOn, IdList *pUsing, int iLock);
SrcList *sqlite3SrcListAppend(SrcList *pList, Token *pTable, Token *pSchema, Token *pDatabase);
char *sqlite3NameFromToken(Token *pName);
SrcList *sqlite3SrcListEnlarge(SrcList *pSrc, int nExtra, int iStart);
int  sqlite3JoinType(Parse *pParse, Token *pA, Token *pB, Token *pC);
int  sqlite3_stricmp(const char *zLeft, const char *zRight);
int  sqlite3_strnicmp(const char *zLeft, const char *zRight, int N);
int  sqlite3GetInt32(const char *zNum, int *pValue);
int  sqlite3GetInt64(const char *zNum, sqlite_int64 *pValue);
u8   sqlite3HexToInt(int h);
Expr *sqlite3ExprFunction(Parse *pParse, ExprList *pList, Token *pToken);
void sqlite3ExprSetHeightAndFlags(Parse *pParse, Expr *p);
IdList *sqlite3IdListAppend(Parse *pParse, IdList *pList, Token *pToken);
void *sqlite3ArrayAllocate(void *pArray, int szEntry, int *pnEntry, int *pIdx);
void sqlite3ShowCmd(Parse *pParse, int iOP, int iFlags, int iOP2, IdList *pList, Expr *pExpr, Token *pToken, Expr *pWild, Expr *pLimit, Expr *pOffset);
void sqlite3UseDatabase(Parse *pParse, Token *pToken);
void sqlite3SetCmd(Parse *pParse, ExprList *opList, int iParam, int iClause);
void sqlite3TxnCmd(int iType, int iWork);

#endif /* _SQLITEINT_H_ */
