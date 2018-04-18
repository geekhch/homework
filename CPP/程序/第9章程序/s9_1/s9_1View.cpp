// s9_1View.cpp : implementation of the CS9_1View class
//

#include "stdafx.h"
#include "s9_1.h"

#include "s9_1Doc.h"
#include "s9_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CS9_1View

IMPLEMENT_DYNCREATE(CS9_1View, CView)

BEGIN_MESSAGE_MAP(CS9_1View, CView)
	//{{AFX_MSG_MAP(CS9_1View)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CS9_1View construction/destruction

CS9_1View::CS9_1View()
{
	// TODO: add construction code here

}

CS9_1View::~CS9_1View()
{
}

BOOL CS9_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CS9_1View drawing

void CS9_1View::OnDraw(CDC* pDC)
{
	CS9_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CS9_1View printing

BOOL CS9_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CS9_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CS9_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CS9_1View diagnostics

#ifdef _DEBUG
void CS9_1View::AssertValid() const
{
	CView::AssertValid();
}

void CS9_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CS9_1Doc* CS9_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CS9_1Doc)));
	return (CS9_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CS9_1View message handlers

int CS9_1View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	AfxMessageBox("窗口正在建立!");		// 新代码
	return 0;
}

void CS9_1View::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	AfxMessageBox("窗口已关闭!"); 			// 新代码	
}
