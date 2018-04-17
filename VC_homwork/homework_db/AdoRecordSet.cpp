/*########################################################################
	Filename: 	adorecordset.cpp
	----------------------------------------------------
	Remarks:	...
	----------------------------------------------------
	Author:		����
	Email:		anyou@sina.com
				anyou@msn.com
	Created:	29/4/2003 8:15
  ########################################################################*/
#include "stdafx.h"
#include "AdoRecordSet.h"
#include <math.h>
#include <io.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/*########################################################################
			 ------------------------------------------------
					CAdoRecordSet class ����/��������
			 ------------------------------------------------
  ########################################################################*/

CAdoRecordSet::CAdoRecordSet()
{
	m_pConnection = NULL;
	m_SearchDirection = adSearchForward;
	m_pRecordset.CreateInstance("ADODB.Recordset");
	#ifdef _DEBUG
	if (m_pRecordset == NULL)
	{
		AfxMessageBox("RecordSet ���󴴽�ʧ��! ��ȷ���Ƿ��ʼ����COM����.");
	}
	#endif
	ASSERT(m_pRecordset != NULL);
}

CAdoRecordSet::CAdoRecordSet(CAdoConnection *pConnection)
{
	m_SearchDirection = adSearchForward;
	m_pConnection = pConnection;
	ASSERT(m_pConnection != NULL);
	m_pRecordset.CreateInstance("ADODB.Recordset");
	#ifdef _DEBUG
	if (m_pRecordset == NULL)
	{
		AfxMessageBox("RecordSet ���󴴽�ʧ��! ��ȷ���Ƿ��ʼ����COM����.");
	}
	#endif
	ASSERT(m_pRecordset != NULL);
}

CAdoRecordSet::~CAdoRecordSet()
{
	Release();
}

/*========================================================================
	Params:		
		- strSQL:		SQL���, ����, �洢���̵��û�־� Recordset �ļ���.
		- CursorType:   ��ѡ. CursorTypeEnum ֵ, ȷ���� Recordset ʱӦ��
					ʹ�õ��α�����. ��Ϊ���г���֮һ.
		[����]				[˵��] 
		-----------------------------------------------
		adOpenForwardOnly	�򿪽���ǰ�����α�. 
		adOpenKeyset		�򿪼��������α�. 
		adOpenDynamic		�򿪶�̬�����α�. 
		adOpenStatic		�򿪾�̬�����α�. 
		-----------------------------------------------
		- LockType:     ��ѡ, ȷ���� Recordset ʱӦ��ʹ�õ���������(����)
					�� LockTypeEnum ֵ, ��Ϊ���г���֮һ.
		[����]				[˵��] 
		-----------------------------------------------
		adLockReadOnly		ֻ�� - ���ܸı�����. 
		adLockPessimistic	����ʽ���� - ͨ��ͨ���ڱ༭ʱ������������Դ�ļ�¼. 
		adLockOptimistic	����ʽ���� - ֻ�ڵ��� Update ����ʱ��������¼. 
		adLockBatchOptimistic ����ʽ������ - ����������ģʽ(����������ģʽ
						���). 
		-----------------------------------------------
		- lOption		��ѡ. ������ֵ, ����ָʾ strSQL ����������. ��Ϊ��
					�г���֮һ.
		[����]				[˵��] 
		-------------------------------------------------
		adCmdText			ָʾstrSQLΪ�����ı�, ����ͨ��SQL���. 
		adCmdTable			ָʾADO����SQL��ѯ������ strSQL �����ı��е�
						������. 
		adCmdTableDirect	ָʾ�����ĸ�����strSQL�������ı��з���������. 
		adCmdStoredProc		ָʾstrSQLΪ�洢����. 
		adCmdUnknown		ָʾstrSQL�����е���������Ϊδ֪. 
		adCmdFile			ָʾӦ����strSQL���������ļ��лָ�����(�����)
						Recordset. 
		adAsyncExecute		ָʾӦ�첽ִ��strSQL. 
		adAsyncFetch		ָʾ����ȡ Initial Fetch Size ������ָ���ĳ�ʼ
						������, Ӧ���첽��ȡ����ʣ�����. ������������δ
						��ȡ, ��Ҫ���߳̽�������ֱ�������¿���. 
		adAsyncFetchNonBlocking ָʾ��Ҫ�߳�����ȡ�ڼ��δ����. ���������
						������δ��ȡ, ��ǰ���Զ��Ƶ��ļ�ĩβ. 
==========================================================================*/
BOOL CAdoRecordSet::Open(LPCTSTR strSQL, long lOption, CursorTypeEnum CursorType, LockTypeEnum LockType)
{
	ASSERT(m_pConnection != NULL);
	ASSERT(m_pRecordset != NULL);
	ASSERT(AfxIsValidString(strSQL));

	if(strcmp(strSQL, _T("")) != 0)
	{
		m_strSQL = strSQL;
	}
	if (m_pConnection == NULL || m_pRecordset == NULL)
	{
		return FALSE;
	}

	if (m_strSQL.IsEmpty())
	{
		ASSERT(FALSE);
		return FALSE;
	}

	try
	{
		if (IsOpen()) Close();
		return SUCCEEDED(m_pRecordset->Open(_variant_t(LPCTSTR(m_strSQL)), 
											_variant_t((IDispatch*)m_pConnection->GetConnection(), true),
											CursorType, LockType, lOption));
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: �򿪼�¼�������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		TRACE(_T("%s\r\n"), GetLastError());
		return FALSE;
	}
}

/*========================================================================
	Name:		ͨ������ִ�ж��������ڵĲ�ѯ, ���� Recordset �����е�����.
    ----------------------------------------------------------
	Params:		Options   ��ѡ. ָʾӰ��ò���ѡ���λ����. ����ò�������
		Ϊ adAsyncExecute, ��ò������첽ִ�в���������ʱ���� 
		RecordsetChangeComplete �¼�
    ----------------------------------------------------------
	Remarks:	ͨ�����·���ԭʼ����ٴμ�������, ��ʹ�� Requery ����ˢ��
	��������Դ�� Recordset �����ȫ������. ���ø÷���������̵��� Close �� 
	Open ����. ������ڱ༭��ǰ��¼��������¼�¼����������.
==========================================================================*/
BOOL CAdoRecordSet::Requery(long Options)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return (m_pRecordset->Requery(Options) == S_OK);
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Requery ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return	FALSE; 
}

/*========================================================================
	Name:		�ӻ������ݿ�ˢ�µ�ǰ Recordset �����е�����.	
    ----------------------------------------------------------
	Params:		AffectRecords:   ��ѡ, AffectEnum ֵ, ���� Resync ������Ӱ
		��ļ�¼��Ŀ, ����Ϊ���г���֮һ.
		[����]				[˵��]
		------------------------------------
		adAffectCurrent		ֻˢ�µ�ǰ��¼. 
		adAffectGroup		ˢ�����㵱ǰ Filter �������õļ�¼.ֻ�н� Filter
						��������Ϊ��ЧԤ���峣��֮һ����ʹ�ø�ѡ��. 
		adAffectAll			Ĭ��ֵ.ˢ�� Recordset �����е����м�¼, ������
						�ڵ�ǰ Filter �������ö����صļ�¼. 
		adAffectAllChapters ˢ�������Ӽ���¼. 

		ResyncValues:   ��ѡ, ResyncEnum ֵ. ָ���Ƿ񸲸ǻ���ֵ. ��Ϊ����
					����֮һ.
		[����]				[˵��] 
		------------------------------------
		adResyncAllValues	Ĭ��ֵ. ��������, ȡ������ĸ���. 
		adResyncUnderlyingValues ����������, ��ȡ������ĸ���. 
    ----------------------------------------------------------
	Remarks:	ʹ�� Resync ��������ǰ Recordset �еļ�¼����������ݿ�����
	ͬ��. ����ʹ�þ�̬�����ǰ���α굫ϣ�������������ݿ��еĸĶ�ʱʮ������.
	����� CursorLocation ��������Ϊ adUseClient, �� Resync ���Է�ֻ���� 
	Recordset �������.
	�� Requery ������ͬ, Resync ����������ִ�� Recordset ����Ļ���������, 
	���������ݿ��е��¼�¼�����ɼ�.
==========================================================================*/
BOOL CAdoRecordSet::Resync(AffectEnum AffectRecords, ResyncEnum ResyncValues)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return (m_pRecordset->Resync(AffectRecords, ResyncValues) == S_OK);
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Resync ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return	FALSE; 
}

/*========================================================================
	Name:		�� Recordset �����ڳ־����ļ���.
    ----------------------------------------------------------
	Params:		
	[strFileName]:   ��ѡ. �ļ�������·����, ���ڱ��� Recordset.
	[PersistFormat]:   ��ѡ. PersistFormatEnum ֵ, ָ������ Recordset ��ʹ
		�õĸ�ʽ. ���������µ�ĳ������: 
		[����]			[˵��] 
		------------------------------
		adPersistADTG	ʹ��ר�õ�"Advanced Data Tablegram"��ʽ����. 
		adPersistXML	(Ĭ��)ʹ�� XML ��ʽ����. 
    ----------------------------------------------------------
	Remarks:	ֻ�ܶԴ򿪵� Recordset ���� Save ����. ���ʹ�� Load ������
	�Դ��ļ��лָ� Recordset. ��� Filter ����Ӱ�� Recordset, ��ֻ���澭��
	ɸѡ����.
		�ڵ�һ�α��� Recordset ʱָ�� FileName. ��������� Save ʱ, Ӧ��
	�� FileName, ���򽫲�������ʱ����. ������ʹ���µ� FileName ���� Save, 
	��ô Recordset �����浽�µ��ļ���, �����ļ���ԭʼ�ļ����Ǵ򿪵�.
==========================================================================*/
BOOL CAdoRecordSet::Save(LPCTSTR strFileName, PersistFormatEnum PersistFormat)
{
	ASSERT(m_pRecordset != NULL);
	ASSERT(IsOpen());
	
	if (m_strFileName == strFileName)
	{
		strFileName = NULL;
	}
	else if(_taccess(strFileName, 0) != -1)
	{
		DeleteFile(strFileName);
		m_strFileName = strFileName;
	}
	else
	{
		m_strFileName = strFileName;
	}

	try
	{
		if (m_pRecordset != NULL) 
		{
			return (m_pRecordset->Save(_bstr_t(strFileName), PersistFormat) == S_OK);
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Save �����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

BOOL CAdoRecordSet::Load(LPCTSTR strFileName)
{
	if (IsOpen()) Close();

	try
	{
		return (m_pRecordset->Open(strFileName, "Provider=MSPersist;", adOpenForwardOnly, adLockOptimistic, adCmdFile) == S_OK);
	}
	catch (_com_error &e)
	{
		TRACE(_T("Warning: Load �����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

/*========================================================================
	Name:		ȡ��ִ�й�����첽 Execute �� Open �����ĵ���.
	-----------------------------------------------------
	Remarks:	ʹ�� Cancel ������ִֹ���첽 Execute �� Open ��������(��ͨ
		�� adAsyncConnect��adAsyncExecute �� adAsyncFetch �������õķ���).
		�������ͼ��ֹ�ķ�����û��ʹ�� adAsyncExecute, �� Cancel ����������
		ʱ����.
==========================================================================*/
BOOL CAdoRecordSet::Cancel()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->Cancel();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Cancel�����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
	Name:		�رմ򿪵Ķ����κ���ض���.
	-----------------------------------------------------
	Remarks:	ʹ�� Close �����ɹر� Recordset �����Ա��ͷ����й�����ϵͳ
		��Դ. �رն��󲢷ǽ������ڴ���ɾ��, ���Ը��������������ò����ڴ˺�
		�ٴδ�. Ҫ��������ڴ�����ȫɾ��, �ɽ������������Ϊ NULL.
			���������������ģʽ�½��б༭, ����Close��������������,Ӧ����
		���� Update �� CancelUpdat ����. ������������ڼ�ر� Recordset ��
		��, �����ϴ� UpdateBatch ���������������޸Ľ�ȫ����ʧ.
			���ʹ�� Clone ���������Ѵ򿪵� Recordset ����ĸ���, �ر�ԭʼ
		Recordset���丱������Ӱ���κ���������.
==========================================================================*/
void CAdoRecordSet::Close()
{
	try
	{
		if (m_pRecordset != NULL && m_pRecordset->State != adStateClosed)
		{
			if (GetEditMode() == adEditNone) CancelUpdate();
			m_pRecordset->Close();
		}
	}
	catch (const _com_error& e)
	{
		TRACE(_T("Warning: �رռ�¼�������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
	}
}

/*========================================================================
	Name:	�ر����Ӳ��ͷŶ���.
	-----------------------------------------------------
	Remarks: �ر����Ӳ��ͷ�CAdoRecordSet����, ���������ϴ���������ȫ�����
		CAdoRecordSet����.
==========================================================================*/
void CAdoRecordSet::Release()
{
	if (IsOpen()) Close();
	m_pRecordset.Release();
	m_pRecordset = NULL;
}


/*########################################################################
			  ------------------------------------------------
							   ��¼�����²���
			  ------------------------------------------------
  ########################################################################*/

/*========================================================================
	Remarks:	��ʼ����µļ�¼. 
==========================================================================*/
BOOL CAdoRecordSet::AddNew()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			if (m_pRecordset->AddNew() == S_OK)
			{
				return TRUE;
			}
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: AddNew ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return	FALSE;
}

/*========================================================================
	Remarks:	�ڵ��� AddNew �ȷ�����, ���ô˷�����ɸ��»��޸�.
==========================================================================*/
BOOL CAdoRecordSet::Update()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			if (m_pRecordset->Update() == S_OK)
			{
				return TRUE;
			}
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Update ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		AfxMessageBox(e.ErrorMessage());
	}
	CancelUpdate();
	return	FALSE;
}

/*========================================================================
	Name:		�����й����������д�����.
    ----------------------------------------------------------
	Params:		AffectRecords   ��ѡ, AffectEnum ֵ. ���� UpdateBatch ����
		��Ӱ��ļ�¼��Ŀ.����Ϊ���³���֮һ.
		[����]				[˵��] 
		------------------------------------
		adAffectCurrent		ֻд�뵱ǰ��¼�Ĺ������. 
		adAffectGroup		д�����㵱ǰ Filter �������õļ�¼�������Ĺ���
			����. ���뽫 Filter ��������Ϊĳ����Ч��Ԥ���峣������ʹ�ø�ѡ��. 
		adAffectAll			(Ĭ��ֵ). д�� Recordset ���������м�¼�Ĺ���
						����, �������ڵ�ǰ Filter �������ö����ص��κμ�¼. 
		adAffectAllChapters д�������Ӽ��Ĺ������. 
    ----------------------------------------------------------
	Remarks:	��������ģʽ�޸� Recordset ����ʱ, ʹ�� UpdateBatch ������
	�� Recordset �����е����и��Ĵ��ݵ��������ݿ�.
	��� Recordset ����֧��������, ��ô���Խ�һ��������¼�Ķ��ظ��Ļ�����
	����, Ȼ���ٵ��� UpdateBatch ����. ����ڵ��� UpdateBatch ����ʱ���ڱ�
	����ǰ��¼��������µļ�¼, ��ô�ڽ������´��͵��ṩ��֮ǰ, ADO ���Զ�
	���� Update ��������Ե�ǰ��¼�����й������.
	   ֻ�ܶԼ�����̬�α�ʹ��������.
==========================================================================*/
BOOL CAdoRecordSet::UpdateBatch(AffectEnum AffectRecords)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return (m_pRecordset->UpdateBatch(AffectRecords) == S_OK);
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: UpdateBatch ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return	FALSE; 
}

/*========================================================================
	Name:		ȡ���ڵ��� Update ����ǰ�Ե�ǰ��¼���¼�¼�������κθ���.
	-----------------------------------------------------
	Remarks:	ʹ�� CancelUpdate ������ȡ���Ե�ǰ��¼�������κθ��Ļ����
	����ӵļ�¼. �ڵ��� Update �������޷������Ե�ǰ��¼���¼�¼�����ĸ�
	��, ���Ǹ����ǿ����� RollbackTrans �����ؾ�������һ����, �����ǿ���
	�� CancelBatch ����ȡ���������µ�һ����.
		����ڵ��� CancelUpdate ����ʱ����¼�¼, ����� AddNew ֮ǰ�ĵ�ǰ
	��¼���ٴγ�Ϊ��ǰ��¼.
		�����δ���ĵ�ǰ��¼������¼�¼, ���� CancelUpdate ��������������.
==========================================================================*/
BOOL CAdoRecordSet::CancelUpdate()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			if (GetEditMode() == adEditNone || m_pRecordset->CancelUpdate() == S_OK)
			{
				return TRUE;
			}
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: CancelUpdate ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
	Name:		ȡ�������������.
	-----------------------------------------------------
	Params:		AffectRecords   ��ѡ�� AffectEnum ֵ, ����CancelBatch ����
		��Ӱ���¼����Ŀ, ��Ϊ���г���֮һ: 
		[����]			[˵��] 
		-------------------------------------------------
		AdAffectCurrent ��ȡ����ǰ��¼�Ĺ������. 
		AdAffectGroup	�����㵱ǰ Filter �������õļ�¼ȡ���������.
						ʹ�ø�ѡ��ʱ,���뽫 Filter ��������Ϊ�Ϸ���Ԥ
						���峣��֮һ. 
		AdAffectAll		Ĭ��ֵ.ȡ�� Recordset ���������м�¼�Ĺ����
						��,�����ɵ�ǰ Filter �������������ص��κμ�¼. 
==========================================================================*/
BOOL CAdoRecordSet::CancelBatch(AffectEnum AffectRecords)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return (m_pRecordset->CancelBatch(AffectRecords) == S_OK);
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: CancelBatch �����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
	Params:		 AffectRecords:  AffectEnum ֵ, ȷ�� Delete ������Ӱ��ļ�
		¼��Ŀ, ��ֵ���������г���֮һ.
		[����]				[˵�� ]
		-------------------------------------------------
		AdAffectCurrent		Ĭ��. ��ɾ����ǰ��¼. 
		AdAffectGroup		ɾ�����㵱ǰ Filter �������õļ�¼. Ҫʹ�ø�ѡ
						��, ���뽫 Filter ��������Ϊ��Ч��Ԥ���峣��֮һ. 
		adAffectAll			ɾ�����м�¼. 
		adAffectAllChapters ɾ�������Ӽ���¼. 
==========================================================================*/
BOOL CAdoRecordSet::Delete(AffectEnum AffectRecords)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return (m_pRecordset->Delete(AffectRecords) == S_OK);
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Delete�����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return	FALSE;
}

/*########################################################################
			  ------------------------------------------------
								��¼����������
			  ------------------------------------------------
  ########################################################################*/

/*========================================================================
	Name:		����ǰ��¼λ���ƶ��� Recordse �еĵ�һ����¼.
==========================================================================*/
BOOL CAdoRecordSet::MoveFirst()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return SUCCEEDED(m_pRecordset->MoveFirst());
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: MoveFirst ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return	FALSE;
}

/*========================================================================
	Name:		����ǰ��¼λ���ƶ��� Recordset �е����һ����¼.
	-----------------------------------------------------
	Remarks:	Recordset �������֧����ǩ��������ƶ�; ������ø÷�����
			��������.
==========================================================================*/
BOOL CAdoRecordSet::MoveLast()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return SUCCEEDED(m_pRecordset->MoveLast());
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: MoveLast ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return	FALSE;
}

/*========================================================================
	Name:		����ǰ��¼λ������ƶ�һ����¼(���¼���Ķ���).
	-----------------------------------------------------
	Remarks:	Recordset �������֧����ǩ������α��ƶ�; ���򷽷����ý���
	������.����׼�¼�ǵ�ǰ��¼���ҵ��� MovePrevious ����, �� ADO ����ǰ��
	¼������ Recordset (BOFΪTrue) ���׼�¼֮ǰ. ��BOF����Ϊ True ʱ�����
	������������. ��� Recordse ����֧����ǩ������α��ƶ�, �� MovePrevious 
	��������������.
==========================================================================*/
BOOL CAdoRecordSet::MovePrevious()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return SUCCEEDED(m_pRecordset->MovePrevious());
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: MovePrevious ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
	return FALSE;	
}

/*========================================================================
	Name:		����ǰ��¼��ǰ�ƶ�һ����¼(�� Recordset �ĵײ�).
	-----------------------------------------------------
	Remarks:	������һ����¼�ǵ�ǰ��¼���ҵ��� MoveNext ����, �� ADO ��
	��ǰ��¼���õ� Recordset (EOFΪ True)��β��¼֮��. �� EOF �����Ѿ�Ϊ 
	True ʱ��ͼ��ǰ�ƶ�����������.
==========================================================================*/
BOOL CAdoRecordSet::MoveNext()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return SUCCEEDED(m_pRecordset->MoveNext());
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: MoveNext ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
	return FALSE;
}

/*========================================================================
	Name:		�ƶ� Recordset �����е�ǰ��¼��λ��.
    ----------------------------------------------------------
	Params:		
		- lRecords    �����ų����ͱ��ʽ, ָ����ǰ��¼λ���ƶ��ļ�¼��.
		- Start    ��ѡ, �ַ����������, ���ڼ�����ǩ. Ҳ��Ϊ���� 
		BookmarkEnum ֵ֮һ: 
		[����]				[˵��] 
		--------------------------------
		adBookmarkCurrent	Ĭ��. �ӵ�ǰ��¼��ʼ. 
		adBookmarkFirst		���׼�¼��ʼ. 
		adBookmarkLast		��β��¼��ʼ. 
==========================================================================*/
BOOL CAdoRecordSet::Move(long lRecords, _variant_t Start)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return SUCCEEDED(m_pRecordset->Move(lRecords, _variant_t(Start)));
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Move ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return	FALSE;
}

/*########################################################################
			  ------------------------------------------------
								  ��¼������
			  ------------------------------------------------
  ########################################################################*/

/*========================================================================
	Name:		ȡ�ü�¼�������״̬(�Ǵ�״̬���ǹر�״̬). ���첽��ʽִ
	�е� Recordset ����, ��˵����ǰ�Ķ���״̬�����ӡ�ִ�л��ǻ�ȡ״̬.
	-----------------------------------------------------
	returns:	�������г���֮һ�ĳ�����ֵ.
		[����]				[˵��] 
		----------------------------------
		adStateClosed		ָʾ�����ǹرյ�. 
		adStateOpen			ָʾ�����Ǵ򿪵�. 
		adStateConnecting	ָʾ Recordset ������������. 
		adStateExecuting	ָʾ Recordset ��������ִ������. 
		adStateFetching		ָʾ Recordset ����������ڱ���ȡ. 
	-----------------------------------------------------
	Remarks:	 ������ʱʹ�� State ����ȷ��ָ������ĵ�ǰ״̬. ��������ֻ
	����. Recordset ����� State ���Կ��������ֵ. ����: �������ִ�����,
	�����Խ��� adStateOpen �� adStateExecuting �����ֵ.
==========================================================================*/
long CAdoRecordSet::GetState()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->GetState();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetState ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	} 
	return -1;
}

BOOL CAdoRecordSet::IsOpen()
{
	try
	{
		return (m_pRecordset != NULL && (GetState() & adStateOpen));
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: IsOpen���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
	Name:		ָʾ�й������»��������������ĵ�ǰ��¼��״̬.
	-----------------------------------------------------
	returns:	��������һ������ RecordStatusEnum ֵ֮��.
		[����]						[˵��]
		-------------------------------------------------
		adRecOK						�ɹ��ظ��¼�¼. 
		adRecNew					��¼���½���. 
		adRecModified				��¼���޸�. 
		adRecDeleted				��¼��ɾ��. 
		adRecUnmodified				��¼û���޸�. 
		adRecInvalid				������ǩ��Ч, ��¼û�б���. 
		adRecMultipleChanges		����Ӱ������¼, ��˼�¼δ������. 
		adRecPendingChanges			���ڼ�¼���ù���Ĳ���, ���δ������. 
		adRecCanceled				���ڲ�����ȡ��, δ�����¼. 
		adRecCantRelease			�������м�¼����, û�б����¼�¼. 
		adRecConcurrencyViolation	���ڿ���ʽ������ʹ����, ��¼δ������. 
		adRecIntegrityViolation		�����û�Υ��������Լ��, ��¼δ������. 
		adRecMaxChangesExceeded		���ڴ��ڹ���������, ��¼δ������. 
		adRecObjectOpen				������򿪵Ĵ�������ͻ, ��¼δ������. 
		adRecOutOfMemory			���ڼ�����ڴ治��, ��¼δ������. 
		adRecPermissionDenied		�����û�û���㹻��Ȩ��, ��¼δ������. 
		adRecSchemaViolation		���ڼ�¼Υ���������ݿ�Ľṹ, ���δ������. 
		adRecDBDeleted				��¼�Ѿ�������Դ��ɾ��. 
	-----------------------------------------------------
	Remarks:	ʹ�� Status ���Բ鿴���������б��޸ĵļ�¼����Щ���ı�����.
	Ҳ��ʹ�� Status ���Բ鿴��������ʱʧ�ܼ�¼��״̬. ����, ���� Recordset
	����� Resync��UpdateBatch �� CancelBatch ����, �������� Recordset ����
	�� Filter ����Ϊ��ǩ����. ʹ�ø�����, �ɼ��ָ����¼Ϊ��ʧ�ܲ��������
	��.
==========================================================================*/
long CAdoRecordSet::GetStatus()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->GetStatus();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetStatus ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	} 
	return -1;
}

/*========================================================================
	Name:		��ȡ��ǰ��¼���м�¼��Ŀ
==========================================================================*/
long CAdoRecordSet::GetRecordCount()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		long count = m_pRecordset->GetRecordCount();

		// ���ado��֧�ִ����ԣ����ֹ������¼��Ŀ --------
		if (count < 0)
		{
			long pos = GetAbsolutePosition();
			MoveFirst();
			count = 0;
			while (!IsEOF()) 
			{
				count++;
				MoveNext();
			}
			SetAbsolutePosition(pos);
		}
		return count;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetRecordCount ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	} 
}

/*========================================================================
	Name:		��ȡ��ǰ��¼�����ֶ���Ŀ
==========================================================================*/
long CAdoRecordSet::GetFieldsCount()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return GetFields()->Count;
	}
	catch(_com_error e)
	{
		TRACE(_T("Warning: GetFieldsCount ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	} 
}
/*========================================================================
	Name:		ָʾͨ����ѯ���� Recordset �ļ�¼�������Ŀ. 
==========================================================================*/
long CAdoRecordSet::GetMaxRecordCount()
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		return m_pRecordset->GetMaxRecords();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetMaxRecordCount ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}
}
BOOL CAdoRecordSet::SetMaxRecordCount(long count)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		m_pRecordset->PutMaxRecords(count);
		return TRUE;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetMaxRecordCount ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

/*========================================================================
	Name:		ָ���Ƿ����ڼ�¼��ͷ
==========================================================================*/
BOOL CAdoRecordSet::IsBOF()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->adoBOF;
	}
	catch(_com_error e)
	{
		TRACE(_T("Warning: IsBOF ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
	Name:		ָ���Ƿ����ڼ�¼��β
==========================================================================*/
BOOL CAdoRecordSet::IsEOF()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->adoEOF;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: IsEOF ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

EditModeEnum CAdoRecordSet::GetEditMode()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			return m_pRecordset->GetEditMode();
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: UpdateBatch ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return adEditNone;
	} 
	return	adEditNone; 
}

long CAdoRecordSet::GetPageCount()
{
	ASSERT(m_pRecordset != NULL);
	
	try
	{
		return m_pRecordset->GetPageCount();
	}
	catch (_com_error &e)
	{
		TRACE(_T("Warning: GetPageCount ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}
}

BOOL CAdoRecordSet::SetCacheSize(const long &lCacheSize)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL && !(GetState() & adStateExecuting))
		{
			m_pRecordset->PutCacheSize(lCacheSize);
		}
	}
	catch (const _com_error& e)
	{
		TRACE(_T("Warning: SetCacheSize���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
	return TRUE;
}

long CAdoRecordSet::GetPageSize()
{
	ASSERT(m_pRecordset != NULL);
	
	try
	{
		return m_pRecordset->GetPageSize();
	}
	catch (_com_error &e)
	{
		TRACE(_T("Warning: GetPageCount ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}
}

/*========================================================================
	name:		ָ����ǰ��¼���ڵ�ҳ.
    ----------------------------------------------------------
	returns:	�û򷵻ش� 1 �� Recordset ���� (PageCount) ����ҳ���ĳ�����
			ֵ�����߷������³���. 
	[����]			[˵��]
	---------------------------------
	adPosUnknown	Recordset Ϊ�գ���ǰλ��δ֪�������ṩ�߲�֧�� AbsolutePage ����.  
	adPosBOF		��ǰ��¼ָ��λ�� BOF(�� BOF ����Ϊ True).  
	adPosEOF		��ǰ��¼ָ��λ�� EOF(�� EOF ����Ϊ True).  
==========================================================================*/
BOOL CAdoRecordSet::SetAbsolutePage(int nPage)
{
	ASSERT(m_pRecordset != NULL);
	
	try
	{
		m_pRecordset->PutAbsolutePage((enum PositionEnum)nPage);		
		return TRUE;
	}
	catch(_com_error &e)
	{
		TRACE(_T("Warning: SetAbsolutePage ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

long CAdoRecordSet::GetAbsolutePage()
{
	ASSERT(m_pRecordset != NULL);
	
	try
	{
		return m_pRecordset->GetAbsolutePage();
	}
	catch(_com_error &e)
	{
		TRACE(_T("Warning: GetAbsolutePage ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}
}

/*========================================================================
	name:		ָ�� Recordset ����ǰ��¼�����λ��. 
    ----------------------------------------------------------
	returns:	���û򷵻ش� 1 �� Recordset ���� (PageCount) ����ҳ���ĳ���
			��ֵ�����߷������³���. 
	[����]			[˵��]
	---------------------------------
	adPosUnknown	Recordset Ϊ�գ���ǰλ��δ֪�������ṩ�߲�֧�� AbsolutePage ����.  
	adPosBOF		��ǰ��¼ָ��λ�� BOF(�� BOF ����Ϊ True).  
	adPosEOF		��ǰ��¼ָ��λ�� EOF(�� EOF ����Ϊ True).  
    ----------------------------------------------------------
	Remarks:		ʹ�� AbsolutePosition ���Կɸ������� Recordset �е����
	λ���ƶ�����¼����ȷ����ǰ��¼�����λ��. �ṩ�߱���֧�ָ����Ե���Ӧ��
	�ܲ���ʹ�ø�����. 
		ͬ AbsolutePage ����һ����AbsolutePosition �� 1 ��ʼ�����ڵ�ǰ��¼
	Ϊ Recordset �еĵ�һ����¼ʱ���� 1. �� RecordCount ���Կɻ�� Recordset 
	������ܼ�¼��. 
		���� AbsolutePosition ����ʱ����ʹ������ָ��λ�ڵ�ǰ�����еļ�¼��
	ADO Ҳ��ʹ����ָ���ļ�¼��ʼ���¼�¼�����¼��ػ���. CacheSize ���Ծ���
	�ü�¼��Ĵ�С. 
		ע��   ���ܽ� AbsolutePosition ������Ϊ����ļ�¼���ʹ��. ɾ��ǰ��
	�ļ�¼ʱ��������¼�ĵ�ǰλ�ý������ı�. ��� Recordset �������²�ѯ��
	���´򿪣����޷���֤������¼����ͬ�� AbsolutePosition. ��ǩ��Ȼ�Ǳ��ֺ�
	���ظ���λ�õ��Ƽ���ʽ���������������͵� Recordset ����Ķ�λʱ��Ψһ��
	��ʽ. 
==========================================================================*/
BOOL CAdoRecordSet::SetAbsolutePosition(int nPosition)
{
	ASSERT(m_pRecordset != NULL);
	
	try
	{
		m_pRecordset->PutAbsolutePosition((enum PositionEnum)nPosition);		
		return TRUE;
	}
	catch(_com_error &e)
	{
		TRACE(_T("Warning: SetAbsolutePosition ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

long CAdoRecordSet::GetAbsolutePosition()
{
	ASSERT(m_pRecordset != NULL);
	
	try
	{
		return m_pRecordset->GetAbsolutePosition();
	}
	catch(_com_error &e)
	{
		TRACE(_T("Warning: GetAbsolutePosition ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}
}

BOOL CAdoRecordSet::SetCursorLocation(CursorLocationEnum CursorLocation)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		m_pRecordset->PutCursorLocation(CursorLocation);
		return TRUE;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: PutCursorLocation ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

CursorLocationEnum CAdoRecordSet::GetCursorLocation()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->GetCursorLocation();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetCursorLocation ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return adUseNone;
	}
}

BOOL CAdoRecordSet::SetCursorType(CursorTypeEnum CursorType)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		m_pRecordset->PutCursorType(CursorType);
		return TRUE;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: SetCursorType ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

CursorTypeEnum CAdoRecordSet::GetCursorType()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->GetCursorType();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetCursorType ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return adOpenUnspecified;
	}
}

/*========================================================================
	Remarks:	Recordset ������� Field ������ɵ� Fields ����. ÿ��Field
	 �����Ӧ Recordset ���е�һ��.
==========================================================================*/
FieldsPtr CAdoRecordSet::GetFields()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->GetFields();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetFields ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return NULL;
	} 
	return NULL;
}

/*========================================================================
	Remarks:	ȡ��ָ�����ֶε��ֶ���.
==========================================================================*/
CString CAdoRecordSet::GetFieldName(long lIndex)
{
	ASSERT(m_pRecordset != NULL);
	CString strFieldName;
	try
	{
		strFieldName = LPCTSTR(m_pRecordset->Fields->GetItem(_variant_t(lIndex))->GetName());
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetFieldName ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
	}
	return strFieldName;
}

/*========================================================================
	name:		ȡ�� Field ����һ����������.
    ----------------------------------------------------------
	returns:	���� Field ����, Attributes ����Ϊֻ��, ��ֵ����Ϊ��������
		һ������ FieldAttributeEnum ֵ�ĺ�.
	  [����]				[˵��] 
	  -------------------------------------------
	  adFldMayDefer			ָʾ�ֶα��ӳ�, ������ӵ��������¼������Դ����
						�ֶ�ֵ, ������ʽ������Щ�ֶ�ʱ�Ž��м���. 
	  adFldUpdatable		ָʾ����д����ֶ�. 
	  adFldUnknownUpdatable ָʾ�ṩ���޷�ȷ���Ƿ����д����ֶ�. 
	  adFldFixed			ָʾ���ֶΰ�����������. 
	  adFldIsNullable		ָʾ���ֶν��� Null ֵ. 
	  adFldMayBeNull		ָʾ���ԴӸ��ֶζ�ȡ Null ֵ. 
	  adFldLong				ָʾ���ֶ�Ϊ���������ֶ�. ��ָʾ����ʹ�� AppendChunk 
						�� GetChunk ����. 
	  adFldRowID			ָʾ�ֶΰ����־õ��б�ʶ��, �ñ�ʶ���޷���д��
						���ҳ��˶��н��б�ʶ(���¼�š�Ψһ��ʶ����)�ⲻ
						�����������ֵ. 
	  adFldRowVersion		ָʾ���ֶΰ����������ٸ��µ�ĳ��ʱ������ڱ��. 
	  adFldCacheDeferred	ָʾ�ṩ�߻������ֶ�ֵ, ����������Ի���Ķ�ȡ. 
==========================================================================*/
long CAdoRecordSet::GetFieldAttributes(long lIndex)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->Fields->GetItem(_variant_t(lIndex))->GetAttributes();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetFieldAttributes ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}
}

long CAdoRecordSet::GetFieldAttributes(LPCTSTR lpszFieldName)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->Fields->GetItem(_variant_t(lpszFieldName))->GetAttributes();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetFieldAttributes ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}
}

/*========================================================================
	Name:		ָʾ Field ����������ĳ���.
    ----------------------------------------------------------
	returns:	����ĳ���ֶζ���ĳ���(���ֽ���)�ĳ�����ֵ.
    ----------------------------------------------------------
	Remarks:	ʹ�� DefinedSize ���Կ�ȷ�� Field �������������.
==========================================================================*/
long CAdoRecordSet::GetFieldDefineSize(long lIndex)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->Fields->GetItem(_variant_t(lIndex))->DefinedSize;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetDefineSize ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}
}

long CAdoRecordSet::GetFieldDefineSize(LPCTSTR lpszFieldName)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->Fields->GetItem(_variant_t(lpszFieldName))->DefinedSize;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetDefineSize ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}
}

/*========================================================================
	Name:	ȡ���ֶε�ֵ��ʵ�ʳ���.
    ----------------------------------------------------------
	returns:	���س�����ֵ.ĳЩ�ṩ���������ø������Ա�Ϊ BLOB ����Ԥ��
			�ռ�, �ڴ������Ĭ��ֵΪ 0.
    ----------------------------------------------------------
	Remarks:	ʹ�� ActualSize ���Կɷ��� Field ����ֵ��ʵ�ʳ���.��������
			�ֶ�,ActualSize ����Ϊֻ��.��� ADO �޷�ȷ�� Field ����ֵ��ʵ
			�ʳ���, ActualSize ���Խ����� adUnknown.
				�����·�����ʾ, ActualSize ��  DefinedSize ����������ͬ: 
			adVarChar ������������󳤶�Ϊ 50 ���ַ��� Field ���󽫷���Ϊ 
			50 �� DefinedSize ����ֵ, ���Ƿ��ص� ActualSize ����ֵ�ǵ�ǰ��
			¼���ֶ��д洢�����ݵĳ���.
==========================================================================*/
long CAdoRecordSet::GetFieldActualSize(long lIndex)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->Fields->GetItem(_variant_t(lIndex))->ActualSize;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetFieldActualSize ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}	
}

long CAdoRecordSet::GetFieldActualSize(LPCTSTR lpszFieldName)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		return m_pRecordset->Fields->GetItem(_variant_t(lpszFieldName))->ActualSize;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetFieldActualSize ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	}	
}

/*========================================================================
	returns:	��������ֵ֮һ. ��Ӧ�� OLE DB ���ͱ�ʶ�����±��˵��������
			���и���.
	  [����]			[˵��] 
	  ---------------------------------------------------------
	  adArray			����������һ������߼� OR ��ָʾ���������������͵�
					��ȫ���� (DBTYPE_ARRAY). 
	  adBigInt			8 �ֽڴ����ŵ����� (DBTYPE_I8). 
	  adBinary			������ֵ (DBTYPE_BYTES). 
	  adBoolean			������ֵ (DBTYPE_BOOL). 
	  adByRef			����������һ������߼� OR ��ָʾ������������������
					�ݵ�ָ�� (DBTYPE_BYREF). 
	  adBSTR			�Կս�β���ַ��� (Unicode) (DBTYPE_BSTR). 
	  adChar			�ַ���ֵ (DBTYPE_STR). 
	  adCurrency		����ֵ (DBTYPE_CY).�������ֵ�С����λ�ù̶���С��
					���Ҳ�����λ����.��ֵ����Ϊ 8 �ֽڷ�ΧΪ10,000 �Ĵ���
					������ֵ. 
	  adDate			����ֵ (DBTYPE_DATE).���ڰ�˫��������ֵ������, ��
					��ȫ����ʾ�� 1899 �� 12 �� 30 ��ʼ��������.С��������
					һ�쵱�е�Ƭ��ʱ��. 
	  adDBDate			����ֵ (yyyymmdd) (DBTYPE_DBDATE). 
	  adDBTime			ʱ��ֵ (hhmmss) (DBTYPE_DBTIME). 
	  adDBTimeStamp		ʱ��� (yyyymmddhhmmss �� 10 �ڷ�֮һ��С��)(DBTYPE_DBTIMESTAMP). 
	  adDecimal			���й̶����Ⱥͷ�Χ�ľ�ȷ����ֵ (DBTYPE_DECIMAL). 
	  adDouble			˫���ȸ���ֵ (DBTYPE_R8). 
	  adEmpty			δָ��ֵ (DBTYPE_EMPTY). 
	  adError			32 - λ������� (DBTYPE_ERROR). 
	  adGUID			ȫ��Ψһ�ı�ʶ�� (GUID) (DBTYPE_GUID). 
	  adIDispatch		OLE ������ Idispatch �ӿڵ�ָ�� (DBTYPE_IDISPATCH). 
	  adInteger			4 �ֽڵĴ��������� (DBTYPE_I4). 
	  adIUnknown		OLE ������ IUnknown �ӿڵ�ָ�� (DBTYPE_IUNKNOWN).
	  adLongVarBinary	��������ֵ. 
	  adLongVarChar		���ַ���ֵ. 
	  adLongVarWChar	�Կս�β�ĳ��ַ���ֵ. 
	  adNumeric			���й̶����Ⱥͷ�Χ�ľ�ȷ����ֵ (DBTYPE_NUMERIC). 
	  adSingle			�����ȸ���ֵ (DBTYPE_R4). 
	  adSmallInt		2 �ֽڴ��������� (DBTYPE_I2). 
	  adTinyInt			1 �ֽڴ��������� (DBTYPE_I1). 
	  adUnsignedBigInt	8 �ֽڲ����������� (DBTYPE_UI8). 
	  adUnsignedInt		4 �ֽڲ����������� (DBTYPE_UI4). 
	  adUnsignedSmallInt 2 �ֽڲ����������� (DBTYPE_UI2). 
	  adUnsignedTinyInt 1 �ֽڲ����������� (DBTYPE_UI1). 
	  adUserDefined		�û�����ı��� (DBTYPE_UDT). 
	  adVarBinary		������ֵ. 
	  adVarChar			�ַ���ֵ. 
	  adVariant			�Զ������� (DBTYPE_VARIANT). 
	  adVector			����������һ������߼� OR ��, ָʾ������ DBVECTOR 
					�ṹ(�� OLE DB ����).�ýṹ����Ԫ�صļ������������� 
					(DBTYPE_VECTOR) ���ݵ�ָ��. 
	  adVarWChar		�Կս�β�� Unicode �ַ���. 
	  adWChar			�Կս�β�� Unicode �ַ��� (DBTYPE_WSTR). 
    ----------------------------------------------------------
	Remarks:	����ָ���ֶε���������.
==========================================================================*/
DataTypeEnum CAdoRecordSet::GetFieldType(long lIndex)
{
	ASSERT(m_pRecordset != NULL);
	try 
	{
		return m_pRecordset->Fields->GetItem(_variant_t(lIndex))->GetType();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetField ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return adEmpty;
	}	
}

DataTypeEnum CAdoRecordSet::GetFieldType(LPCTSTR lpszFieldName)
{
	ASSERT(m_pRecordset != NULL);
	try 
	{
		return m_pRecordset->Fields->GetItem(_variant_t(lpszFieldName))->GetType();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetField�����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return adEmpty;
	}	
}

BOOL CAdoRecordSet::IsFieldNull(LPCTSTR lpFieldName)
{
	try
	{
		_variant_t vt = m_pRecordset->Fields->GetItem(lpFieldName)->Value;
		return (vt.vt == VT_NULL);
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: IsFieldNull ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

BOOL CAdoRecordSet::IsFieldNull(long index)
{
	try
	{
		_variant_t vt = m_pRecordset->Fields->GetItem(_variant_t(index))->Value;
		return (vt.vt == VT_NULL);
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: IsFieldNull ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

/*========================================================================
	Name:	ȡ��ָ���е��ֶζ����ָ��.	
==========================================================================*/
FieldPtr CAdoRecordSet::GetField(long lIndex)
{
	try
	{
		return GetFields()->GetItem(_variant_t(lIndex));
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetField�����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return NULL;
	}
}

FieldPtr CAdoRecordSet::GetField(LPCTSTR lpszFieldName)
{
	try
	{
		return GetFields()->GetItem(_variant_t(lpszFieldName));
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetField�����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return NULL;
	}
}

/*########################################################################
			  ------------------------------------------------
								  �����ֶε�ֵ
			  ------------------------------------------------
  ########################################################################*/
BOOL CAdoRecordSet::PutCollect(long index, const _variant_t &value)
{
	ASSERT(m_pRecordset != NULL);
	ASSERT(index < GetFieldsCount());
	try
	{
		if (m_pRecordset != NULL) 
		{
			m_pRecordset->PutCollect(_variant_t(index), value);
			return	TRUE;
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: PutCollect ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return	FALSE;
}

BOOL CAdoRecordSet::PutCollect(LPCSTR strFieldName, const _variant_t &value)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL) 
		{
			m_pRecordset->put_Collect(_variant_t(strFieldName), value);
			return TRUE;
		}
	}
	catch (_com_error e)
	{
		return FALSE;
		TRACE(_T("Warning: PutCollect ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
	} 
	return	FALSE;
}

BOOL CAdoRecordSet::PutCollect(long index, const bool &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(index) != adBoolean)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	return PutCollect(index, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const bool &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(strFieldName) != adBoolean)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif
	
	return PutCollect(strFieldName, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(long index, const BYTE &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(index) != adUnsignedTinyInt)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	return PutCollect(index, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const BYTE &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(strFieldName) != adUnsignedTinyInt)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif
	
	return PutCollect(strFieldName, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(long index, const short &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(index) != adSmallInt)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif
	
	return PutCollect(index, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const short &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(strFieldName) != adSmallInt)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif
	
	return PutCollect(strFieldName, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(long index, const int &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(index) != adInteger)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif
	
	return PutCollect(index, _variant_t(long(value)));
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const int &value)
{
	ASSERT(m_pRecordset != NULL);
	
	#ifdef _DEBUG
	if (GetFieldType(strFieldName) != adInteger)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	return PutCollect(strFieldName, _variant_t(long(value)));
}

BOOL CAdoRecordSet::PutCollect(long index, const long &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(index) != adBigInt)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif
	
	return PutCollect(index, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const long &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(strFieldName) != adBigInt)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif
	
	return PutCollect(strFieldName, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(long index, const DWORD &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(index) != adUnsignedBigInt)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	_variant_t vt;
	vt.vt = VT_UI4;
	vt.ulVal = value;
	return PutCollect(index, vt);
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const DWORD &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(strFieldName) != adUnsignedBigInt)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	_variant_t vt;
	vt.vt = VT_UI4;
	vt.ulVal = value;
	return PutCollect(strFieldName, vt);
}

BOOL CAdoRecordSet::PutCollect(long index, const float &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(index) != adSingle)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif
	
	return PutCollect(index, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const float &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(strFieldName) != adSingle)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	return PutCollect(strFieldName, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(long index, const double &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(index) != adDouble)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	return PutCollect(index, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const double &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(strFieldName) != adDouble)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif
	
	return PutCollect(strFieldName, _variant_t(value));
}

BOOL CAdoRecordSet::PutCollect(long index, const COleDateTime &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (   GetFieldType(index) != adDate
		&& GetFieldType(index) != adDBDate
		&& GetFieldType(index) != adDBTime
		&& GetFieldType(index) != adDBTimeStamp)
	{
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	}
	#endif

	_variant_t vt;
	vt.vt = VT_DATE;
	vt.date = value;
	return PutCollect(index, vt);
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const COleDateTime &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (   GetFieldType(strFieldName) != adDate
		&& GetFieldType(strFieldName) != adDBDate
		&& GetFieldType(strFieldName) != adDBTime
		&& GetFieldType(strFieldName) != adDBTimeStamp)
	{
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	}
	#endif

	_variant_t vt;
	vt.vt = VT_DATE;
	vt.date = value;
	return PutCollect(strFieldName, vt);
}

BOOL CAdoRecordSet::PutCollect(long index, const COleCurrency &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(index) != adCurrency)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	if (value.m_status == COleCurrency::invalid) return FALSE;

	_variant_t vt;
	vt.vt = VT_CY;
	vt.cyVal = value.m_cur;
	return PutCollect(index, vt);
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const COleCurrency &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (GetFieldType(strFieldName) != adCurrency)
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	if (value.m_status == COleCurrency::invalid) return FALSE;

	_variant_t vt;
	vt.vt = VT_CY;
	vt.cyVal = value.m_cur;
	return PutCollect(strFieldName, vt);
}

BOOL CAdoRecordSet::PutCollect(long index, const CString &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (! (GetFieldType(index) == adVarChar
		|| GetFieldType(index) == adChar
		|| GetFieldType(index) == adLongVarChar
		|| GetFieldType(index) == adVarWChar
		|| GetFieldType(index) == adWChar
		|| GetFieldType(index) == adLongVarWChar))
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	_variant_t vt;
	vt.vt = value.IsEmpty() ? VT_NULL : VT_BSTR;
	vt.bstrVal = value.AllocSysString();
	return PutCollect(index, vt);
}

BOOL CAdoRecordSet::PutCollect(LPCTSTR strFieldName, const CString &value)
{
	ASSERT(m_pRecordset != NULL);
	#ifdef _DEBUG
	if (! (GetFieldType(strFieldName) == adVarChar
		|| GetFieldType(strFieldName) == adChar
		|| GetFieldType(strFieldName) == adLongVarChar
		|| GetFieldType(strFieldName) == adVarWChar
		|| GetFieldType(strFieldName) == adWChar
		|| GetFieldType(strFieldName) == adLongVarWChar))
		TRACE(_T("Warning: ��Ҫ�������ֶ���������������Ͳ���; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	#endif

	_variant_t vt;
	vt.vt = value.IsEmpty() ? VT_NULL : VT_BSTR;
	vt.bstrVal = value.AllocSysString();
	return PutCollect(strFieldName, vt);
}


/*########################################################################
			  ------------------------------------------------
							    ��ȡ�ֶε�ֵ
			  ------------------------------------------------
  ########################################################################*/
BOOL CAdoRecordSet::GetCollect(long index, COleDateTime &value)
{
	ASSERT(m_pRecordset != NULL);
	
	try
	{
		value = vartodate(m_pRecordset->GetCollect(_variant_t(index)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value.SetStatus(COleDateTime::null);
		return FALSE;
	}
}

BOOL CAdoRecordSet::GetCollect(LPCTSTR strFieldName, COleDateTime &value)
{
	ASSERT(m_pRecordset != NULL);
	
	try
	{
		value = vartodate(m_pRecordset->GetCollect(_variant_t(strFieldName)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value.SetStatus(COleDateTime::null);
		return FALSE;
	}
}

BOOL CAdoRecordSet::GetCollect(long index, COleCurrency &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartocy(m_pRecordset->GetCollect(_variant_t(index)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value.m_status = COleCurrency::null;
		return FALSE;
	}
}

BOOL CAdoRecordSet::GetCollect(LPCTSTR strFieldName, COleCurrency &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartocy(m_pRecordset->GetCollect(_variant_t(strFieldName)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value.m_status = COleCurrency::null;
		return FALSE;
	}
}

BOOL CAdoRecordSet::GetCollect(long index,  bool &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartobool(m_pRecordset->GetCollect(_variant_t(index)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = false;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(LPCSTR strFieldName,  bool &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartobool(m_pRecordset->GetCollect(_variant_t(strFieldName)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = false;
		return FALSE;
	} 	
}


BOOL CAdoRecordSet::GetCollect(long index,  BYTE &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartoby(m_pRecordset->GetCollect(_variant_t(index)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(LPCSTR strFieldName,  BYTE &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartoby(m_pRecordset->GetCollect(_variant_t(strFieldName)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(long index,  short &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartoi(m_pRecordset->GetCollect(_variant_t(index)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(LPCSTR strFieldName,  short &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartoi(m_pRecordset->GetCollect(_variant_t(strFieldName)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(long index,  int &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = (int)vartol(m_pRecordset->GetCollect(_variant_t(index)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
	return FALSE;
}

BOOL CAdoRecordSet::GetCollect(LPCSTR strFieldName,  int &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = (int)vartol(m_pRecordset->GetCollect(_variant_t(strFieldName)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(long index,  long &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartol(m_pRecordset->GetCollect(_variant_t(index)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(LPCSTR strFieldName,  long &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartol(m_pRecordset->GetCollect(_variant_t(strFieldName)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
	return FALSE;
}

BOOL CAdoRecordSet::GetCollect(long index,  DWORD &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		_variant_t result = m_pRecordset->GetCollect(_variant_t(index));
		switch (result.vt)
		{
		case VT_UI4:
		case VT_I4:
			value = result.ulVal;
			break;
		case VT_NULL:
		case VT_EMPTY:
			value = 0;
			break;
		default:
			TRACE(_T("Warning: �޷���ȡ��Ӧ���ֶ�, �������Ͳ�ƥ��; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
			return FALSE;
		}		
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(LPCSTR strFieldName,  DWORD &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		_variant_t result = m_pRecordset->GetCollect(_variant_t(strFieldName));
		switch (result.vt)
		{
		case VT_UI4:
		case VT_I4:
			value = result.ulVal;
			break;
		case VT_NULL:
		case VT_EMPTY:
			value = 0;
			break;
		default:
			TRACE(_T("Warning: �޷���ȡ��Ӧ���ֶ�, �������Ͳ�ƥ��; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
			return FALSE;
		}		
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(long index,  float &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		_variant_t result = m_pRecordset->GetCollect(_variant_t(index));
		switch (result.vt)
		{
		case VT_R4:
			value = result.fltVal;
			break;
		case VT_UI1:
		case VT_I1:
			value = result.bVal;
			break;
		case VT_UI2:
		case VT_I2:
			value = result.iVal;
			break;
		case VT_NULL:
		case VT_EMPTY:
			value = 0;
			break;
		default:
			TRACE(_T("Warning: �޷���ȡ��Ӧ���ֶ�, �������Ͳ�ƥ��; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
			return FALSE;
		}		
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(LPCSTR strFieldName,  float &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		_variant_t result = m_pRecordset->GetCollect(_variant_t(strFieldName));
		switch (result.vt)
		{
		case VT_R4:
			value = result.fltVal;
			break;
		case VT_UI1:
		case VT_I1:
			value = result.bVal;
			break;
		case VT_UI2:
		case VT_I2:
			value = result.iVal;
			break;
		case VT_NULL:
		case VT_EMPTY:
			value = 0;
			break;
		default:
			TRACE(_T("Warning: �޷���ȡ��Ӧ���ֶ�, �������Ͳ�ƥ��; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
			return FALSE;
		}		
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(long index,  double &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartof(m_pRecordset->GetCollect(_variant_t(index)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(LPCSTR strFieldName,  double &value)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		value = vartof(m_pRecordset->GetCollect(_variant_t(strFieldName)));
		return TRUE;
	}
	catch (_com_error e)
	{
		value = 0;
		return FALSE;
	} 	
}

BOOL CAdoRecordSet::GetCollect(long index, CString& strValue)
{
	ASSERT(m_pRecordset != NULL);
	if (index < 0 || index >= GetFieldsCount())
	{
		return FALSE;
	}

	try
	{
		if (!IsOpen())
		{
			//MessageBox(NULL, _T("���ݿ�����Ѿ��Ͽ�,\r\n���������ӡ�Ȼ������."), _T("��ʾ"), MB_ICONINFORMATION);
			return FALSE;
		} 
		if (m_pRecordset->adoEOF)
		{
			return FALSE;
		}
		_variant_t value = m_pRecordset->GetCollect(_variant_t(index));
		strValue = vartostr(value);
		return TRUE;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: �ֶη���ʧ��. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}

	return FALSE;
}

BOOL CAdoRecordSet::GetCollect(LPCTSTR strFieldName, CString &strValue)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (!IsOpen())
		{
			//MessageBox(NULL, _T("���ݿ�����Ѿ��Ͽ�,\r\n���������ӡ�Ȼ������."), _T("��ʾ"), MB_ICONINFORMATION);
			return FALSE;
		} 
		if (m_pRecordset->adoEOF)
		{
			return FALSE;
		}
		_variant_t value = m_pRecordset->GetCollect(_variant_t(LPCTSTR(strFieldName)));
		strValue = vartostr(value);
		return TRUE;	
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: �ֶη���ʧ��. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}

	return FALSE;
}

/*########################################################################
			  ------------------------------------------------
				������׷�ӵ������ı������������� Field ����. 
			  ------------------------------------------------
  ########################################################################*/
BOOL CAdoRecordSet::AppendChunk(FieldPtr pField, LPVOID lpData, UINT nBytes)
{
	SAFEARRAY FAR *pSafeArray = NULL;
	SAFEARRAYBOUND rgsabound[1];

	try
	{
		rgsabound[0].lLbound = 0;
		rgsabound[0].cElements = nBytes;
		pSafeArray = SafeArrayCreate(VT_UI1, 1, rgsabound);

		for (long i = 0; i < (long)nBytes; i++)
		{
			UCHAR &chData	= ((UCHAR*)lpData)[i];
			HRESULT hr = SafeArrayPutElement(pSafeArray, &i, &chData);
			if (FAILED(hr))	return FALSE;
		}

		_variant_t varChunk;
		varChunk.vt = VT_ARRAY | VT_UI1;
		varChunk.parray = pSafeArray;

		return (pField->AppendChunk(varChunk) == S_OK);
	}
	catch (_com_error &e)
	{
		TRACE(_T("Warning: AppendChunk ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

BOOL CAdoRecordSet::AppendChunk(long index, LPVOID lpData, UINT nBytes)
{
	ASSERT(m_pRecordset != NULL);
	ASSERT(lpData != NULL);
	if (adFldLong & GetFieldAttributes(index))
	{
		return AppendChunk(GetField(index), lpData, nBytes);
	}
	else return FALSE;
}

BOOL CAdoRecordSet::AppendChunk(LPCSTR strFieldName, LPVOID lpData, UINT nBytes)
{
	ASSERT(m_pRecordset != NULL);
	ASSERT(lpData != NULL);
	if (adFldLong & GetFieldAttributes(strFieldName))
	{
		return AppendChunk(GetField(strFieldName), lpData, nBytes);
	}
	else return FALSE;
}

BOOL CAdoRecordSet::AppendChunk(long index, LPCTSTR lpszFileName)
{
	ASSERT(m_pRecordset != NULL);
	ASSERT(lpszFileName != NULL);
	BOOL bret = FALSE;
	if (adFldLong & GetFieldAttributes(index))
	{
		CFile file;
		if (file.Open(lpszFileName, CFile::modeRead))
		{
			long length = (long)file.GetLength();
			char *pbuf = new char[length];
			if (pbuf != NULL && file.Read(pbuf, length) == (DWORD)length)
			{
				bret = AppendChunk(GetField(index), pbuf, length);
			}
			if (pbuf != NULL) delete[] pbuf;
		}
		file.Close();
	}
	return bret;
}

BOOL CAdoRecordSet::AppendChunk(LPCSTR strFieldName, LPCTSTR lpszFileName)
{
	ASSERT(m_pRecordset != NULL);
	ASSERT(lpszFileName != NULL);
	BOOL bret = FALSE;
	if (adFldLong & GetFieldAttributes(strFieldName))
	{
		CFile file;
		if (file.Open(lpszFileName, CFile::modeRead))
		{
			long length = (long)file.GetLength();
			char *pbuf = new char[length];
			if (pbuf != NULL && file.Read(pbuf, length) == (DWORD)length)
			{
				bret = AppendChunk(GetField(strFieldName), pbuf, length);
			}
			if (pbuf != NULL) delete[] pbuf;
		}
		file.Close();
	}
	return bret;
}

BOOL CAdoRecordSet::GetChunk(FieldPtr pField, LPVOID lpData)
{
	ASSERT(pField != NULL);
	ASSERT(lpData != NULL);

	UCHAR chData;
	long index = 0;

	while (index < pField->ActualSize)
	{ 
		try
		{
			_variant_t varChunk = pField->GetChunk(100);
			if (varChunk.vt != (VT_ARRAY | VT_UI1))
			{
				return FALSE;
			}
			
            for (long i = 0; i < 100; i++)
            {
                if (SUCCEEDED( SafeArrayGetElement(varChunk.parray, &i, &chData) ))
                {
					((UCHAR*)lpData)[index] = chData;
                    index++;
                }
                else
				{
                    break;
				}
            }
		}
		catch (_com_error e)
		{
			TRACE(_T("Warning: GetChunk ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
			return FALSE;
		}
	}

	return TRUE;
}

BOOL CAdoRecordSet::GetChunk(long index, LPVOID lpData)
{
	if (adFldLong & GetFieldAttributes(index))
		return  GetChunk(GetField(index), lpData);
	else return FALSE;
}

BOOL CAdoRecordSet::GetChunk(LPCSTR strFieldName, LPVOID lpData)
{
	if (adFldLong & GetFieldAttributes(strFieldName))
		return  GetChunk(GetField(strFieldName), lpData);
	else return FALSE;
}

BOOL CAdoRecordSet::GetChunk(long index, CBitmap &bitmap)
{
	return GetChunk(GetFieldName(index), bitmap);
}

BOOL CAdoRecordSet::GetChunk(LPCSTR strFieldName, CBitmap &bitmap)
{		
	BOOL bret = FALSE;
	long size = GetFieldActualSize(strFieldName);
	if ((adFldLong & GetFieldAttributes(strFieldName)) && size > 0)
	{
		BYTE *lpData = new BYTE[size];
		
		if (GetChunk(GetField(strFieldName), (LPVOID)lpData))
		{
			BITMAPFILEHEADER bmpHeader;
			DWORD bmfHeaderLen = sizeof(bmpHeader);
			strncpy((LPSTR)&bmpHeader, (LPSTR)lpData, bmfHeaderLen);
			
			// �Ƿ���λͼ ----------------------------------------
			if (bmpHeader.bfType == (*(WORD*)"BM"))
			{
				BYTE* lpDIBBits = lpData + bmfHeaderLen;
				BITMAPINFOHEADER &bmpiHeader = *(LPBITMAPINFOHEADER)lpDIBBits;
				BITMAPINFO &bmpInfo = *(LPBITMAPINFO)lpDIBBits;
				lpDIBBits = lpData + ((BITMAPFILEHEADER *)lpData)->bfOffBits;

				// ����λͼ --------------------------------------
				CDC dc;
				HDC hdc = GetDC(NULL);
				dc.Attach(hdc);
				HBITMAP hBmp = CreateDIBitmap(dc.m_hDC, &bmpiHeader, CBM_INIT, lpDIBBits, &bmpInfo, DIB_RGB_COLORS);
				if (bitmap.GetSafeHandle() != NULL) bitmap.DeleteObject();
				bitmap.Attach(hBmp);
				dc.Detach();
				ReleaseDC(NULL, hdc);
				bret = TRUE;
			}
		}
		delete[] lpData;
		lpData = NULL;
	}
	return bret;
}

/*########################################################################
			  ------------------------------------------------
								   ��������
			  ------------------------------------------------
  ########################################################################*/

_RecordsetPtr CAdoRecordSet::operator =(_RecordsetPtr &pRecordSet)
{
	Close();
	if (pRecordSet != NULL)
	{
		m_pRecordset = NULL;
		m_pRecordset = pRecordSet;
		return m_pRecordset;
	}
	return NULL;
}

/*========================================================================
	Name:	ȷ��ָ���� Recordset �����Ƿ�֧���ض����͵Ĺ���.	
    ----------------------------------------------------------
	Params:	CursorOptions   ������, ����һ���������� CursorOptionEnum ֵ.
	[����]				[˵��] 
	------------------------------------
	adAddNew			��ʹ�� AddNew ��������¼�¼. 
	adApproxPosition	�ɶ�ȡ������ AbsolutePosition �� AbsolutePage ������. 
	adBookmark			��ʹ�� Bookmark ���Ի�ö��ض���¼�ķ���. 
	adDelete			����ʹ�� Delete ����ɾ����¼. 
	adHoldRecords		���Լ��������¼���߸�����һ������λ�ö������ύ��
					�й���ĸ���. 
	adMovePrevious		��ʹ�� MoveFirst �� MovePrevious ����, �Լ� Move ��
					GetRows ��������ǰ��¼λ������ƶ�������ʹ����ǩ. 
	adResync			ͨ�� Resync ����, ʹ���ڻ��������ݿ��пɼ������ݸ�
					���α�. 
	adUpdate			��ʹ�� Update �����޸����е�����. 
	adUpdateBatch		����ʹ��������(UpdateBatch �� CancelBatch ����) ��
					�����鴫����ṩ��. 
	adIndex				����ʹ�� Index ������������. 
	adSeek				����ʹ�� Seek ������λ Recordset �е���. 
    ----------------------------------------------------------
	returns:	���ز�����ֵ, ָʾ�Ƿ�֧�� CursorOptions ��������ʶ�����й���.
    ----------------------------------------------------------
	Remarks:	ʹ�� Supports ����ȷ�� Recordset ������֧�ֵĹ�������. ��
	�� Recordset ����֧������Ӧ������ CursorOptions �еĹ���, ��ô Supports
	�������� True.���򷵻� False.
	ע��   ���� Supports �����ɶԸ����Ĺ��ܷ��� True, �������ܱ�֤�ṩ�߿�
	��ʹ���������л����¾���Ч. Supports ����ֻ�����ṩ���Ƿ�֧��ָ���Ĺ���
	(�ٶ�����ĳЩ����). ����, Supports ��������ָʾ Recordset ����֧�ָ���
	(��ʹ�α���ڶ����ĺϲ�), ������ĳЩ����Ȼ�޷�����.
==========================================================================*/
BOOL CAdoRecordSet::Supports(CursorOptionEnum CursorOptions)
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset != NULL)
		{
			return m_pRecordset->Supports(CursorOptions);
		}
	}
	catch (const _com_error& e)
	{
		TRACE(_T("Warning: Supports���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
	return FALSE;
}

/*========================================================================
	name:		Ϊ Recordset �е�����ָ��ɸѡ����.
==========================================================================*/
BOOL CAdoRecordSet::SetFilter(LPCTSTR lpszFilter)
{
	ASSERT(m_pRecordset != NULL);
	ASSERT(IsOpen());
	
	try
	{
		m_pRecordset->PutFilter(lpszFilter);
		return TRUE;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: SetFilter ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

/*========================================================================
	name:		Ϊ Recordset �е�����ָ����������.
==========================================================================*/
BOOL CAdoRecordSet::SetSort(LPCTSTR lpszCriteria)
{
	ASSERT(IsOpen());
	
	try
	{
		m_pRecordset->PutSort(lpszCriteria);
		return TRUE;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: SetFilter ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

/*========================================================================
	name:		����Ψһ��ʶ Recordset �����е�ǰ��¼����ǩ��
==========================================================================*/
_variant_t CAdoRecordSet::GetBookmark()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (IsOpen())
		{
			m_varBookmark = m_pRecordset->GetBookmark();
			return m_varBookmark;
		}		
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetBookmark ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
	}
	return _variant_t((long)adBookmarkFirst);
}

/*========================================================================
	name:		�� Recordset ����ĵ�ǰ��¼����Ϊ����Ч��ǩ����ʶ�ļ�¼��
==========================================================================*/
BOOL CAdoRecordSet::SetBookmark(_variant_t varBookMark)
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		if (IsOpen() && varBookMark.vt != VT_EMPTY && varBookMark.vt != VT_NULL)
		{
			m_pRecordset->PutBookmark(varBookMark);
			return TRUE;
		}	
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: SetBookmark ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
	}
	return FALSE;
}

void CAdoRecordSet::SetAdoConnection(CAdoConnection *pConnection)
{
	m_pConnection = pConnection;
}

_RecordsetPtr& CAdoRecordSet::GetRecordset()
{
	return m_pRecordset;
}

CString CAdoRecordSet::GetLastError()
{
	ASSERT(m_pConnection != NULL);
	return m_pConnection->GetLastErrorText();
}

/*========================================================================
	name:	���������� Recordset ������ͬ�ĸ��� Recordset ���󡣿�ѡ��ָ��
	�ø���Ϊֻ����
==========================================================================*/
BOOL CAdoRecordSet::Clone(CAdoRecordSet &pRecordSet)
{
	ASSERT(m_pRecordset != NULL);
	
	try
	{
		pRecordSet = m_pRecordset->Clone(adLockUnspecified);
		return TRUE;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Clone ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

/*========================================================================
	name:		���� Recordset ������ָ����׼�ļ�¼. ��������׼�����¼��
			λ���������ҵ��ļ�¼�ϣ�����λ�ý������ڼ�¼����ĩβ. 
    ----------------------------------------------------------
	params:		[criteria]:   �ַ���������ָ�������������������Ƚϲ�������
				ֵ�����. 
				[searchDirection]:    ��ѡ�� SearchDirectionEnum ֵ��ָ����
	��Ӧ�ӵ�ǰ�л�����һ����Ч�п�ʼ. ��ֵ��Ϊ adSearchForward �� adSearchBackward. 
	�������ڼ�¼���Ŀ�ʼ����ĩβ������ searchDirection ֵ����. 
	[����]			[˵��]
	---------------------------------
	adSearchForward 	
	adSearchBackward	
    ----------------------------------------------------------
	Remarks:	criteria �е�"�Ƚϲ�����"������">"(����)��"<"(С��)��"="(��
	��)��">="(���ڻ����)��"<="(С�ڻ����)��"<>"(������)��"like"(ģʽƥ��).  
		criteria �е�ֵ�������ַ�������������������. �ַ���ֵ�Ե����ŷֽ�(��
	"state = 'WA'"). ����ֵ��"#"(���ּǺ�)�ֽ�(��"start_date > #7/22/97#"). 
		��"�Ƚϲ�����"Ϊ"like"�����ַ���"ֵ"���԰���"*"(ĳ�ַ��ɳ���һ�λ�
	���)����"_"(ĳ�ַ�ֻ����һ��). (��"state like M_*"�� Maine �� Massachusetts 
	ƥ��.). 
==========================================================================*/
BOOL CAdoRecordSet::Find(LPCTSTR lpszFind, SearchDirectionEnum SearchDirection)
{
	ASSERT(m_pRecordset != NULL);
	ASSERT(AfxIsValidString(lpszFind));

	try
	{
		if (strcmp(lpszFind, _T("")) != 0)
		{
			m_strFind = lpszFind;
		}

		if (m_strFind.IsEmpty()) return FALSE;

		m_pRecordset->Find(_bstr_t(m_strFind), 0, SearchDirection, "");
		
		if ((IsEOF() || IsBOF()) )
		{
			return FALSE;
		}
		else
		{
			m_SearchDirection = SearchDirection;
			GetBookmark();
			return TRUE;
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Find ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

/*========================================================================
	name:		������һ�����������ļ�¼.
==========================================================================*/
BOOL CAdoRecordSet::FindNext()
{
	ASSERT(m_pRecordset != NULL);

	try
	{
		if (m_strFind.IsEmpty()) return FALSE;

		m_pRecordset->Find(_bstr_t(m_strFind), 1, m_SearchDirection, m_varBookmark);
		
		if ((IsEOF() || IsBOF()) )
		{
			return FALSE;
		}
		else
		{
			GetBookmark();
			return TRUE;
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: FindNext ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

BOOL CAdoRecordSet::RecordBinding(CADORecordBinding &pAdoRecordBinding)
{
	m_pAdoRecordBinding = NULL;

	try
	{
		if (SUCCEEDED(m_pRecordset->QueryInterface(__uuidof(IADORecordBinding), (LPVOID*)&m_pAdoRecordBinding)))
		{
			if (SUCCEEDED(m_pAdoRecordBinding->BindToRecordset(&pAdoRecordBinding)))
			{
				return TRUE;
			}	
		}
		return TRUE;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: RecordBinding ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}
}

BOOL CAdoRecordSet::AddNew(CADORecordBinding &pAdoRecordBinding)
{
	try
	{
		if (m_pAdoRecordBinding->AddNew(&pAdoRecordBinding) == S_OK)
		{
			m_pAdoRecordBinding->Update(&pAdoRecordBinding);
			return TRUE;
		}
		return FALSE;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: AddNew ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	}	
}