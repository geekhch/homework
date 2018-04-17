
// homework_dbDlg.h : 头文件
//

#pragma once
#include "Resource.h"
#include "daoOption.h"
#include "afxwin.h"

// Chomework_dbDlg 对话框
class Chomework_dbDlg : public CDialogEx
{
// 构造
public:
	Chomework_dbDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_HOMEWORK_DB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;
	daoOption* ado;

	// 生成的消息映射函数
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
