
// homework_dbDlg.h : ͷ�ļ�
//

#pragma once
#include "Resource.h"
#include "daoOption.h"
#include "afxwin.h"

// Chomework_dbDlg �Ի���
class Chomework_dbDlg : public CDialogEx
{
// ����
public:
	Chomework_dbDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HOMEWORK_DB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;
	daoOption* ado;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void ShowMsg(CString str);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
	CEdit m_edit;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
