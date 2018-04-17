/*########################################################################
	���ļ�����: 	ado.h
	����  �ơ�:		ADO ��װ��.
	����  ����:		0.20
	����  �ߡ�:		����
	��E-mail��:		anyou@sina.com
	 ---------------------------------------------------------
	������ʱ�䡿:		20/1/2003 19:08
	���޸�ʱ�䡿:		09/4/2003
	 ---------------------------------------------------------
	���汾��ʷ��:
		[0.20]  :   ��װ�� CAdoCommand ��.
			[-15/4/2003-]
			
		[0.11]  :   ������һЩ bug.
					ɾ�� oleinit() ����, ��Ϊ���ò��ס�
					�����˼�¼����ȡ����.
			[-09/4/2003-]

		[0.10]	:	��Ҫ���� CAdoConnection �� CAdoRecordSet ������, ��װ��
			��ado�ĳ��õĲ�������.
			[-20/1/2003-]
	 ---------------------------------------------------------
	��ʹ��˵����:
		1. ����������ָ�� msado15.dll ��ȫ·��, һ���� "C:\Program Files\
		   Common Files\System\ADO\" Ŀ¼��.
		2. ��ʹ�ñ���֮ǰ����Ҫ��ʼ�� COM ����, ���Ե��� CoInitialize(NULL)  
		   ����ʼ��, �� CoUninitialize() �ͷ�;
		3. ��ʹ�ü�¼������ǰ�����ȵ��� CAdoConnection::Open() �������ݿ�,
		   ���Ӻ�ɸ���� CAdoRecordSet ����ʹ��, �������ر����ݿ�.
		4. ʹ�ü�¼��ִ��SQL���֮ǰ, Ҫʹ�ù������������ SetAdoConnection() 
		   ���������Ӷ���.
		5. �ڱ�������в����������ı��뾯��:
		   warning: unary minus operator applied to unsigned type, result
		   still unsigned
		   �������˾������,������ StdAfx.h �ļ��м�������һ�д����Խ�ֹ
		   �˾���: 	#pragma warning(disable:4146) 
  ########################################################################*/
#if !defined(_ANYOU_COOL_ADO_H)
#define _ANYOU_COOL_ADO_H

#if _MSC_VER > 1000
#pragma once
#endif 
 
// ���� ado �� -----------------------------------------------------------
#pragma warning(disable:4146)
#import "C:\Program Files\Common Files\System\ADO\msado15.dll" named_guids rename("EOF","adoEOF"), rename("BOF","adoBOF")
#pragma warning(default:4146)
using namespace ADODB;  

#include <icrsint.h>
class CAdoConnection;
#include "AdoRecordSet.h"
#include "AdoCommand.h"

// ��ֵ����ת�� -----------------------------------
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
// ����/���� ------------------------------------------
public:
	CAdoConnection();
	virtual ~CAdoConnection();

protected:
	void Release();

// ���� -----------------------------------------------
public:
	// ���Ӷ��� ----------------------------------
	_ConnectionPtr& GetConnection() {return m_pConnection;};

	// �쳣��Ϣ ----------------------------------
	CString GetLastErrorText();
	ErrorsPtr GetErrors();
	ErrorPtr  GetError(long index);

	// �����ִ� ----------------------------------
	CString GetConnectionText() {return m_strConnect;}

	// ������Ϣ ----------------------------------
	CString GetProviderName();
	CString GetVersion();
	CString GetDefaultDatabase();

	// ����״̬ ----------------------------------
	BOOL IsOpen();
	long GetState();
	
	// ����ģʽ ----------------------------------
	ConnectModeEnum GetMode();
	BOOL SetMode(ConnectModeEnum mode);

	// ����ʱ�� ----------------------------------
	long GetConnectTimeOut();
	BOOL SetConnectTimeOut(long lTime = 5);
	
	// ����Դ��Ϣ -------------------------------
	_RecordsetPtr OpenSchema(SchemaEnum QueryType);

// ���� -----------------------------------------------
public:
	// ���ݿ����� --------------------------------
	BOOL Open(LPCTSTR lpszConnect =_T(""), long lOptions = adConnectUnspecified);
	BOOL ConnectSQLServer(CString dbsrc, CString dbname, CString user, CString pass, long lOptions = adConnectUnspecified);
	BOOL ConnectAccess(CString dbpath, CString pass = _T(""), long lOptions = adConnectUnspecified);
	BOOL OpenUDLFile(LPCTSTR strFileName, long lOptions = adConnectUnspecified);
	void Close();

// ���� -----------------------------------------------
public:
	// ������ ----------------------------------
	long BeginTrans();
	BOOL RollbackTrans();
	BOOL CommitTrans();

	// ִ�� SQL ��� ------------------------------
	_RecordsetPtr Execute(LPCTSTR strSQL, long lOptions = adCmdText);
	BOOL Cancel();

	_ConnectionPtr	m_pConnection;
// ���� -----------------------------------------------
protected:
	CString			m_strConnect;
};

#endif // !defined(_ANYOU_COOL_ADO_H)










































