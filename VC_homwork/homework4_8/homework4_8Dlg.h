
// homework4_8Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// Chomework4_8Dlg 对话框
class Chomework4_8Dlg : public CDialogEx
{
// 构造
public:
	Chomework4_8Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_HOMEWORK4_8_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
