// s9_2.h : main header file for the S9_2 application
//

#if !defined(AFX_S9_2_H__172F41C5_BFA4_41F5_9C44_FE611A778FB8__INCLUDED_)
#define AFX_S9_2_H__172F41C5_BFA4_41F5_9C44_FE611A778FB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CS9_2App:
// See s9_2.cpp for the implementation of this class
//

class CS9_2App : public CWinApp
{
public:
	CS9_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS9_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CS9_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S9_2_H__172F41C5_BFA4_41F5_9C44_FE611A778FB8__INCLUDED_)
