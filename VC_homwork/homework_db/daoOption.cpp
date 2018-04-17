#include "stdafx.h"
#include "daoOption.h"


daoOption::daoOption(CString sql)
{
	
	CString m_strConnectionString="DSN=ADOLinkMySQL;User ID=root;password=123;Data Source=local;";
	try
	{
		m_pConnection=new CAdoConnection();
		if(m_pConnection->Open(m_strConnectionString)){
			bOk=TRUE;
			m_bConnected=TRUE;
			m_pRecordSet = new CAdoRecordSet(m_pConnection); //�󶨽��������ǰ����
			m_pRecordSet->Open(sql);
		}else{
			ShowMsg("�����Ӳ��ɹ���");
		}
	}
	catch(...)
	{
		ShowMsg("�����ݿ����");
		bOk=FALSE;
	}
}



daoOption::~daoOption(void)
{
	m_pRecordSet->Close();
	m_pConnection->Close();
	delete m_pConnection;
	delete m_pRecordSet;
	m_pConnection = NULL;
	m_pRecordSet = NULL;
}

void daoOption::getRecord(CString sql)
{
	//strSql="insert into mqtt_test(temp) values('" + CTime::GetCurrentTime().Format("%Y")+"')";
	try{
		m_msg = "";
		ShowMsg("id    temp\r\n--------");
		CString id,temp;
		m_pRecordSet->MoveFirst();
		while(!m_pRecordSet->IsEOF()){
			m_pRecordSet->GetCollect("id", id);
			m_pRecordSet->GetCollect("temp", temp);
			ShowMsg(id+"    " + temp);
			m_pRecordSet->MoveNext();
		}
		ShowMsg("\r\n");
	}catch(...){
		ShowMsg("��ѯ����");
		bOk=FALSE;
	}
}

void daoOption::putRecord(CString temp)
{
	CString sql;
	sql.Format("INSERT INTO mqtt_test(temp) VALUES(%s)",temp);
	try{
		m_pConnection->Execute(sql);
		AfxMessageBox(sql);
	}catch(_com_error e){
		TRACE("Warning: �򿪼�¼�������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n", e.ErrorMessage(), __FILE__, __LINE__);
	}
}

void daoOption::ShowMsg(CString msg)
{
	//Chomework_dbDlg::m_edit.SetDlgItemTextA(IDC_EDIT1,msg);
	m_msg += msg+"\r\n";
}


CAdoRecordSet daoOption::getRecordSet(void)
{
	return *m_pRecordSet;
}

void daoOption::updateRecord(CString old_data, CString new_data)
{
	CString sql;
	sql.Format("UPDATE mqtt_test SET temp = %s WHERE temp=%s",new_data,old_data);
	try{
		m_pConnection->Execute(sql);
		AfxMessageBox(sql);
	}catch(_com_error e){
		TRACE("Warning: �򿪼�¼�������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n", e.ErrorMessage(), __FILE__, __LINE__);
	}
}

void daoOption::deleteData(CString id, CString temp)
{
	CString sqlx,sqly;
		sqlx.Format("delete from mqtt_test where id=%s",id);
		sqly.Format("delete from mqtt_test where temp=%s",temp);
	try{
		m_pConnection->Execute(sqlx);
		m_pConnection->Execute(sqly);
	}catch(_com_error e){
		TRACE("Warning: �򿪼�¼�������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n", e.ErrorMessage(), __FILE__, __LINE__);
	}
}
