
// homework_treeView.cpp : Chomework_treeView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Chomework_treeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Chomework_treeView ����/����

Chomework_treeView::Chomework_treeView()
{
	// TODO: �ڴ˴���ӹ������

}

Chomework_treeView::~Chomework_treeView()
{
}

BOOL Chomework_treeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Chomework_treeView ����

void Chomework_treeView::OnDraw(CDC* /*pDC*/)
{
	Chomework_treeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Chomework_treeView ��ӡ


void Chomework_treeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Chomework_treeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Chomework_treeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Chomework_treeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// Chomework_treeView ���

#ifdef _DEBUG
void Chomework_treeView::AssertValid() const
{
	CView::AssertValid();
}

void Chomework_treeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Chomework_treeDoc* Chomework_treeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Chomework_treeDoc)));
	return (Chomework_treeDoc*)m_pDocument;
}
#endif //_DEBUG


// Chomework_treeView ��Ϣ�������
