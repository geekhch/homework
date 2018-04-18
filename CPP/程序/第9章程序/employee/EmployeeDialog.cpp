// EmployeeDialog.cpp : implementation file
//

#include "stdafx.h"
#include "employee.h"
#include "EmployeeDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDialog dialog


CEmployeeDialog::CEmployeeDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CEmployeeDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmployeeDialog)
	m_num = _T("");
	m_name = _T("");
	m_sex = _T("");
	m_year = 0;
	m_month = 0;
	m_day = 0;
	m_basicSalary = 0.0f;
	//}}AFX_DATA_INIT
}


void CEmployeeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmployeeDialog)
	DDX_Text(pDX, IDC_EDIT1, m_num);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_sex);
	DDX_Text(pDX, IDC_EDIT4, m_year);
	DDX_Text(pDX, IDC_EDIT5, m_month);
	DDX_Text(pDX, IDC_EDIT6, m_day);
	DDX_Text(pDX, IDC_EDIT7, m_basicSalary);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmployeeDialog, CDialog)
	//{{AFX_MSG_MAP(CEmployeeDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDialog message handlers

void CEmployeeDialog::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);					// 用编辑框内容更新关联的成员变量	
	CDialog::OnOK();
}
