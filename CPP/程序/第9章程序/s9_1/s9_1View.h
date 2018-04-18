// s9_1View.h : interface of the CS9_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_S9_1VIEW_H__10743D84_D67E_4C35_ADDC_A276EEF535C1__INCLUDED_)
#define AFX_S9_1VIEW_H__10743D84_D67E_4C35_ADDC_A276EEF535C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CS9_1View : public CView
{
protected: // create from serialization only
	CS9_1View();
	DECLARE_DYNCREATE(CS9_1View)

// Attributes
public:
	CS9_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS9_1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CS9_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CS9_1View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in s9_1View.cpp
inline CS9_1Doc* CS9_1View::GetDocument()
   { return (CS9_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S9_1VIEW_H__10743D84_D67E_4C35_ADDC_A276EEF535C1__INCLUDED_)
