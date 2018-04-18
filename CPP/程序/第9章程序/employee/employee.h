// employee.h : main header file for the EMPLOYEE application
//

#if !defined(AFX_EMPLOYEE_H__DBDFAAD3_3F1D_41A7_A535_AD07B3747483__INCLUDED_)
#define AFX_EMPLOYEE_H__DBDFAAD3_3F1D_41A7_A535_AD07B3747483__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEmployeeApp:
// See employee.cpp for the implementation of this class
//

struct CDateType			// 日期
{	
	int year;				// 年
	int month;				// 月
	int day;				// 日
	CDateType() {}			// 构造函数
	CDateType(int y, int m, int d): year(y), month(m), day(d){}// 构造函数
};

struct CEmployeeType		// 员工
{
	char num[11];			// 编号
	char name[19];			// 姓名
	char sex[3];			// 性别
	CDateType birthday;		// 生日
	float basicSalary;		// 基本工资
	CEmployeeType() {}		// 构造函数
	CEmployeeType(char no[], char nm[], char sx[], int y, int m, int d, float bs)
		: birthday(y, m, d), basicSalary(bs) // 构造函数
	{
		strcpy(num, no);	// 复制编号
		strcpy(name, nm);	// 复制姓名
		strcpy(sex, sx);	// 复制基本工资
	}
};

class CEmployeeApp : public CWinApp
{
public:
	CEmployeeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployeeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEmployeeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEE_H__DBDFAAD3_3F1D_41A7_A535_AD07B3747483__INCLUDED_)
