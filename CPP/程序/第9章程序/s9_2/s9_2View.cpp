// s9_2View.cpp : implementation of the CS9_2View class
//

#include "stdafx.h"
#include "s9_2.h"

#include "s9_2Doc.h"
#include "s9_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CS9_2View

IMPLEMENT_DYNCREATE(CS9_2View, CView)

BEGIN_MESSAGE_MAP(CS9_2View, CView)
	//{{AFX_MSG_MAP(CS9_2View)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CS9_2View construction/destruction

CS9_2View::CS9_2View()
{
	// TODO: add construction code here

}

CS9_2View::~CS9_2View()
{
}

BOOL CS9_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CS9_2View drawing

void CS9_2View::OnDraw(CDC* pDC)
{
	CS9_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CS9_2View printing

BOOL CS9_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CS9_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CS9_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CS9_2View diagnostics

#ifdef _DEBUG
void CS9_2View::AssertValid() const
{
	CView::AssertValid();
}

void CS9_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CS9_2Doc* CS9_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CS9_2Doc)));
	return (CS9_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CS9_2View message handlers

void CS9_2View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	char	buf[80];						//定义字符数组
	CClientDC	dc(this);					//将当前视图对象定义成设备实例
	sprintf(buf, "[%03d,%03d]", point.x, point.y);	//将鼠标坐标值复制到buf中
	dc.TextOut(60, 80, buf);				//在(60, 80)处显示鼠标坐标值
	
	CView::OnMouseMove(nFlags, point);
}
