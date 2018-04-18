#if !defined(AFX_EMPLOYEEDIALOG_H__3126B660_B2C7_4556_9974_9D114675B16F__INCLUDED_)
#define AFX_EMPLOYEEDIALOG_H__3126B660_B2C7_4556_9974_9D114675B16F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmployeeDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDialog dialog

class CEmployeeDialog : public CDialog
{
// Construction
public:
	CEmployeeDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEmployeeDialog)
	enum { IDD = IDD_DIALOG_EMPLOYEE };
	CString	m_num;
	CString	m_name;
	CString	m_sex;
	int		m_year;
	int		m_month;
	int		m_day;
	float	m_basicSalary;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployeeDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmployeeDialog)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEEDIALOG_H__3126B660_B2C7_4556_9974_9D114675B16F__INCLUDED_)
