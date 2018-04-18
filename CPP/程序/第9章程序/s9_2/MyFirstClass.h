#if !defined(AFX_MYFIRSTCLASS_H__199D3F0A_F031_4064_A244_F35A940E5859__INCLUDED_)
#define AFX_MYFIRSTCLASS_H__199D3F0A_F031_4064_A244_F35A940E5859__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyFirstClass.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyFirstClass view

class CMyFirstClass : public CView
{
protected:
	CMyFirstClass();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyFirstClass)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFirstClass)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyFirstClass();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyFirstClass)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFIRSTCLASS_H__199D3F0A_F031_4064_A244_F35A940E5859__INCLUDED_)
