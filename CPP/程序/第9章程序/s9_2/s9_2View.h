// s9_2View.h : interface of the CS9_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_S9_2VIEW_H__5709E589_E14D_4AD7_9618_F33DBB51C78B__INCLUDED_)
#define AFX_S9_2VIEW_H__5709E589_E14D_4AD7_9618_F33DBB51C78B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CS9_2View : public CView
{
protected: // create from serialization only
	CS9_2View();
	DECLARE_DYNCREATE(CS9_2View)

// Attributes
public:
	CS9_2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS9_2View)
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
	virtual ~CS9_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CS9_2View)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in s9_2View.cpp
inline CS9_2Doc* CS9_2View::GetDocument()
   { return (CS9_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S9_2VIEW_H__5709E589_E14D_4AD7_9618_F33DBB51C78B__INCLUDED_)
