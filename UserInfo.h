#ifndef __UserInfo_h__
#define __UserInfo_h__
#include <string>
#include <Log/Logger.h>

#include "DBConfig.h"
#include "MysqlProt.h"
#include "Types.h"
#include "DBPoolManager.h"
#include "Privilege.h"

enum eSessionParam
{
	SESSION_PARAM_GLOBAL_SCAN,
	SESSION_PARAM_PROCESS_DATA_TIMEOUT,
	SESSION_PARAM_IGNORE_SHARDING_ERROR,

	SESSION_PARAM_SIZE,
};

struct stSubQuery
{
	stEndpoint ep;
	std::string strSubSql;
	time_t iStartTime;

	stSubQuery()
	{
		iStartTime = 0;
	}
};

struct UserInfo
{
	// user context
	int         iLogin;       // 1: login ok
	std::string strDefaultDB; // init db
	std::string strUsername;
	std::string strHost;
	int         iCharset;
	stUserPriv  userPriv;
	int         aiSessionParam[SESSION_PARAM_SIZE];
	unsigned long long iLastInsertId;

	// sql context
	bool        bExec;
	std::string strSql;       // current sql
	time_t      iStartTime;   // current sql query startTime
	void        *pParse;
	bool        bDelete;      // for delete
	bool        bUpdate;      // for update
	bool        bInsert;      // for insert
	bool        bJoin;        // for select
	bool        bSingleNode;  // for select

	bool        bHasDistinct;
	bool        bHasAgg;
	bool        bSameGroupOrder;
	std::vector<int> vecFieldAggType;
	int         iSelectFieldSize;
	int         iGroupFieldSize;
	int         iHavingFieldSize;
	int         iOrderFieldSize;
	std::vector<stSubQuery> vecExecSubQuery;
	std::vector<stSubQuery> vecWaitSubQuery;
	StMysqlQueryResponse interResult;

	// transaction context
	int         iInTrans;     // 1: in transaction
	int         iStartTrans;
	time_t      iTransStartTime;  // current transaction startTime
	stEndpoint  transEndpoint;

	UserInfo()
	{
		iLogin = 0;
		iCharset = 0x21; // UTF8_GENERAL_CI
		iLastInsertId = 0;
		iStartTime = 0;
		bExec = false;
		pParse = NULL;
		bDelete = false;
		bUpdate = false;
		bInsert = false;
		bJoin = false;
		bSingleNode = false;
		bHasDistinct = false;
		bHasAgg = false;
		bSameGroupOrder = false;
		iSelectFieldSize = 0;
		iGroupFieldSize = 0;
		iHavingFieldSize = 0;
		iOrderFieldSize = 0;
		iInTrans = 0;
		iStartTrans = 0;
		iTransStartTime = 0;

		memset(aiSessionParam, 0, sizeof(aiSessionParam));
	}

	void ResetSqlContext()
	{
		strSql = "";
		iStartTime = 0;
		bExec = false;
		pParse = NULL;
		bDelete = false;
		bUpdate = false;
		bInsert = false;
		bJoin = false;
		bSingleNode = false;
		bHasDistinct = false;
		bHasAgg = false;
		bSameGroupOrder = false;
		vecFieldAggType.clear();
		iSelectFieldSize = 0;
		iGroupFieldSize = 0;
		iHavingFieldSize = 0;
		iOrderFieldSize = 0;
		vecExecSubQuery.clear();
		vecWaitSubQuery.clear();

		interResult.iStep = RESP_STEP_INIT;
		interResult.iStatus = RESP_STATUS_OK;
		interResult.textResult.iColumnCnt = 0;
		interResult.textResult.iServerStatus = 0;
		interResult.textResult.iWarningsCount = 0;
		interResult.textResult.vecColumnFields.clear();
		interResult.textResult.vecColumnValues.clear();
		interResult.errorPacket.iErrorcode = 0;
		interResult.errorPacket.iProtocol = MYSQL_PROTOCOL_VERSION_41;
		interResult.errorPacket.strErrorMsg = "";
		interResult.errorPacket.strSqlState = "";
		interResult.okPacket.iAffectRows = 0;
		interResult.okPacket.iLastInsertId = 0;
		interResult.okPacket.iStatusFlags = 0;
		interResult.okPacket.iWarningNum = 0;
		interResult.okPacket.strStatusInfo = "";
		interResult.okPacket.strSessionStateInfo = "";
	}

	void ResetTransContext()
	{
		iInTrans = 0;
		iStartTrans = 0;
		iTransStartTime = 0;

		transEndpoint.iDBType = DB_NULL;
		transEndpoint.iPort = 0;
		transEndpoint.iConnectTimeout = 0;
		transEndpoint.iQueryTimeout = 0;
		transEndpoint.iPoolMaxSize = 0;
		transEndpoint.strHost = "";
		transEndpoint.strUser = "";
		transEndpoint.strPasd = "";
		transEndpoint.strDatabase = "";
		transEndpoint.strTable = "";
	}
};

#endif
