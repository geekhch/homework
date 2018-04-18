// employeeView.h : interface of the CEmployeeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMPLOYEEVIEW_H__2950E96E_27F5_4D0F_884A_C448E6594C3B__INCLUDED_)
#define AFX_EMPLOYEEVIEW_H__2950E96E_27F5_4D0F_884A_C448E6594C3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEmployeeView : public CView
{
protected: // create from serialization only
	CEmployeeView();
	DECLARE_DYNCREATE(CEmployeeView)

// Attributes
public:
	CEmployeeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployeeView)
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
	virtual ~CEmployeeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEmployeeView)
	afx_msg void OnMenuitemShow();
	afx_msg void OnMenuitemInput();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in employeeView.cpp
inline CEmployeeDoc* CEmployeeView::GetDocument()
   { return (CEmployeeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEEVIEW_H__2950E96E_27F5_4D0F_884A_C448E6594C3B__INCLUDED_)
