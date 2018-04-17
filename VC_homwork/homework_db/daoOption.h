#pragma once

#include "AdoRecordSet.h"
#include "Resource.h"

class daoOption
{
protected:
	CAdoConnection* m_pConnection;
	CAdoRecordSet* m_pRecordSet;
	BOOL bOk;
	BOOL m_bConnected;
	CString m_str;
public:

	CString m_msg;
	daoOption(CString sql = "SELECT * FROM mqtt_test");
	~daoOption(void);
	void getRecord(CString sql);
	void ShowMsg(CString msg);
	CAdoRecordSet getRecordSet(void);
	CString getString(){return m_str;}
	void putRecord(CString temp);
	void updateRecord(CString old_data, CString new_data);
	void deleteData(CString id="Null",CString temp="Null");
};