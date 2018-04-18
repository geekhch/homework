// s9_1.h : main header file for the S9_1 application
//

#if !defined(AFX_S9_1_H__D68A52BE_2BF3_4C6F_A95E_A47B694A297F__INCLUDED_)
#define AFX_S9_1_H__D68A52BE_2BF3_4C6F_A95E_A47B694A297F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CS9_1App:
// See s9_1.cpp for the implementation of this class
//

class CS9_1App : public CWinApp
{
public:
	CS9_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS9_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CS9_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S9_1_H__D68A52BE_2BF3_4C6F_A95E_A47B694A297F__INCLUDED_)
