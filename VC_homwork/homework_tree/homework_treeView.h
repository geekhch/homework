
// homework_treeView.h : Chomework_treeView ��Ľӿ�
//

#pragma once


class Chomework_treeView : public CView
{
protected: // �������л�����
	Chomework_treeView();
	DECLARE_DYNCREATE(Chomework_treeView)

// ����
public:
	Chomework_treeDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Chomework_treeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // homework_treeView.cpp �еĵ��԰汾
inline Chomework_treeDoc* Chomework_treeView::GetDocument() const
   { return reinterpret_cast<Chomework_treeDoc*>(m_pDocument); }
#endif

