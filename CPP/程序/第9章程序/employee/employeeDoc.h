// employeeDoc.h : interface of the CEmployeeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMPLOYEEDOC_H__3B87D3F7_1995_47B9_9A07_9F979B554E22__INCLUDED_)
#define AFX_EMPLOYEEDOC_H__3B87D3F7_1995_47B9_9A07_9F979B554E22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEmployeeDoc : public CDocument
{
protected: // create from serialization only
	CEmployeeDoc();
	DECLARE_DYNCREATE(CEmployeeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployeeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEmployeeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEmployeeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEEDOC_H__3B87D3F7_1995_47B9_9A07_9F979B554E22__INCLUDED_)
