// MyFirstClass.cpp : implementation file
//

#include "stdafx.h"
#include "s9_2.h"
#include "MyFirstClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFirstClass

IMPLEMENT_DYNCREATE(CMyFirstClass, CView)

CMyFirstClass::CMyFirstClass()
{
}

CMyFirstClass::~CMyFirstClass()
{
}


BEGIN_MESSAGE_MAP(CMyFirstClass, CView)
	//{{AFX_MSG_MAP(CMyFirstClass)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFirstClass drawing

void CMyFirstClass::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CMyFirstClass diagnostics

#ifdef _DEBUG
void CMyFirstClass::AssertValid() const
{
	CView::AssertValid();
}

void CMyFirstClass::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyFirstClass message handlers
