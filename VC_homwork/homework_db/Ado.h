/*########################################################################
	【文件名】: 	ado.h
	【名  称】:		ADO 封装类.
	【版  本】:		0.20
	【作  者】:		成真
	【E-mail】:		anyou@sina.com
	 ---------------------------------------------------------
	【创建时间】:		20/1/2003 19:08
	【修改时间】:		09/4/2003
	 ---------------------------------------------------------
	【版本历史】:
		[0.20]  :   封装了 CAdoCommand 类.
			[-15/4/2003-]
			
		[0.11]  :   修正了一些 bug.
					删除 oleinit() 函数, 因为觉得不妥。
					增加了记录集存取函数.
			[-09/4/2003-]

		[0.10]	:	主要包括 CAdoConnection 和 CAdoRecordSet 两个类, 封装了
			对ado的常用的操作方法.
			[-20/1/2003-]
	 ---------------------------------------------------------
	【使用说明】:
		1. 必须在下面指明 msado15.dll 的全路径, 一般在 "C:\Program Files\
		   Common Files\System\ADO\" 目录下.
		2. 在使用本类之前必须要初始化 COM 环境, 可以调用 CoInitialize(NULL)  
		   来初始化, 用 CoUninitialize() 释放;
		3. 在使用记录集对象前必须先调用 CAdoConnection::Open() 连接数据库,
		   连接后可给多个 CAdoRecordSet 对象使用, 用完后须关闭数据库.
		4. 使用记录集执行SQL语句之前, 要使用构建方法或调用 SetAdoConnection() 
		   关联到连接对象.
		5. 在编译过程中不用理会下面的编译警告:
		   warning: unary minus operator applied to unsigned type, result
		   still unsigned
		   如果不想此警告出现,可以在 StdAfx.h 文件中加入这样一行代码以禁止
		   此警告: 	#pragma warning(disable:4146) 
  ########################################################################*/
#if !defined(_ANYOU_COOL_ADO_H)
#define _ANYOU_COOL_ADO_H

#if _MSC_VER > 1000
#pragma once
#endif 
 
// 导入 ado 库 -----------------------------------------------------------
#pragma warning(disable:4146)
#import "C:\Program Files\Common Files\System\ADO\msado15.dll" named_guids rename("EOF","adoEOF"), rename("BOF","adoBOF")
#pragma warning(default:4146)
using namespace ADODB;  

#include <icrsint.h>
class CAdoConnection;
#include "AdoRecordSet.h"
#include "AdoCommand.h"

// 数值类型转换 -----------------------------------
COleDateTime vartodate(const _variant_t& var);
COleCurrency vartocy(const _variant_t& var);
bool vartobool(const _variant_t& var);
BYTE vartoby(const _variant_t& var);
short vartoi(const _variant_t& var);
long vartol(const _variant_t& var);
double vartof(const _variant_t& var);
CString vartostr(const _variant_t& var);

/*########################################################################
			  ------------------------------------------------
						    CAdoConnection class
			  ------------------------------------------------
  ########################################################################*/
class CAdoConnection
{
// 构建/析构 ------------------------------------------
public:
	CAdoConnection();
	virtual ~CAdoConnection();

protected:
	void Release();

// 属性 -----------------------------------------------
public:
	// 连接对象 ----------------------------------
	_ConnectionPtr& GetConnection() {return m_pConnection;};

	// 异常信息 ----------------------------------
	CString GetLastErrorText();
	ErrorsPtr GetErrors();
	ErrorPtr  GetError(long index);

	// 连接字串 ----------------------------------
	CString GetConnectionText() {return m_strConnect;}

	// 连接信息 ----------------------------------
	CString GetProviderName();
	CString GetVersion();
	CString GetDefaultDatabase();

	// 连接状态 ----------------------------------
	BOOL IsOpen();
	long GetState();
	
	// 连接模式 ----------------------------------
	ConnectModeEnum GetMode();
	BOOL SetMode(ConnectModeEnum mode);

	// 连接时间 ----------------------------------
	long GetConnectTimeOut();
	BOOL SetConnectTimeOut(long lTime = 5);
	
	// 数据源信息 -------------------------------
	_RecordsetPtr OpenSchema(SchemaEnum QueryType);

// 操作 -----------------------------------------------
public:
	// 数据库连接 --------------------------------
	BOOL Open(LPCTSTR lpszConnect =_T(""), long lOptions = adConnectUnspecified);
	BOOL ConnectSQLServer(CString dbsrc, CString dbname, CString user, CString pass, long lOptions = adConnectUnspecified);
	BOOL ConnectAccess(CString dbpath, CString pass = _T(""), long lOptions = adConnectUnspecified);
	BOOL OpenUDLFile(LPCTSTR strFileName, long lOptions = adConnectUnspecified);
	void Close();

// 处理 -----------------------------------------------
public:
	// 事务处理 ----------------------------------
	long BeginTrans();
	BOOL RollbackTrans();
	BOOL CommitTrans();

	// 执行 SQL 语句 ------------------------------
	_RecordsetPtr Execute(LPCTSTR strSQL, long lOptions = adCmdText);
	BOOL Cancel();

	_ConnectionPtr	m_pConnection;
// 数据 -----------------------------------------------
protected:
	CString			m_strConnect;
};

#endif // !defined(_ANYOU_COOL_ADO_H)










































