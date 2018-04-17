
// homework_treeView.cpp : Chomework_treeView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "homework_tree.h"
#endif

#include "homework_treeDoc.h"
#include "homework_treeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Chomework_treeView

IMPLEMENT_DYNCREATE(Chomework_treeView, CView)

BEGIN_MESSAGE_MAP(Chomework_treeView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Chomework_treeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Chomework_treeView 构造/析构

Chomework_treeView::Chomework_treeView()
{
	// TODO: 在此处添加构造代码

}

Chomework_treeView::~Chomework_treeView()
{
}

BOOL Chomework_treeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Chomework_treeView 绘制

void Chomework_treeView::OnDraw(CDC* /*pDC*/)
{
	Chomework_treeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Chomework_treeView 打印


void Chomework_treeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Chomework_treeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Chomework_treeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Chomework_treeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void Chomework_treeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Chomework_treeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Chomework_treeView 诊断

#ifdef _DEBUG
void Chomework_treeView::AssertValid() const
{
	CView::AssertValid();
}

void Chomework_treeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Chomework_treeDoc* Chomework_treeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Chomework_treeDoc)));
	return (Chomework_treeDoc*)m_pDocument;
}
#endif //_DEBUG


// Chomework_treeView 消息处理程序
