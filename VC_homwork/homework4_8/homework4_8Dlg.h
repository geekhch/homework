
// homework4_8Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// Chomework4_8Dlg �Ի���
class Chomework4_8Dlg : public CDialogEx
{
// ����
public:
	Chomework4_8Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HOMEWORK4_8_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
};
