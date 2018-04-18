// employeeView.cpp : implementation of the CEmployeeView class
//

#include "stdafx.h"
#include "employee.h"
#include "EmployeeDialog.h"				// Ա����Ϣ�Ի���
#include <iostream>               		// ����Ԥ��������
#include <fstream>               		// ����Ԥ��������
using namespace std;					// ʹ�������ռ�std 

#include "employeeDoc.h"
#include "employeeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView

IMPLEMENT_DYNCREATE(CEmployeeView, CView)

BEGIN_MESSAGE_MAP(CEmployeeView, CView)
	//{{AFX_MSG_MAP(CEmployeeView)
	ON_COMMAND(ID_MENUITEM_SHOW, OnMenuitemShow)
	ON_COMMAND(ID_MENUITEM_INPUT, OnMenuitemInput)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView construction/destruction

CEmployeeView::CEmployeeView()
{
	// TODO: add construction code here

}

CEmployeeView::~CEmployeeView()
{
}

BOOL CEmployeeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView drawing

void CEmployeeView::OnDraw(CDC* pDC)
{
	CEmployeeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView printing

BOOL CEmployeeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEmployeeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEmployeeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView diagnostics

#ifdef _DEBUG
void CEmployeeView::AssertValid() const
{
	CView::AssertValid();
}

void CEmployeeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEmployeeDoc* CEmployeeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEmployeeDoc)));
	return (CEmployeeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView message handlers

void CEmployeeView::OnMenuitemShow() 
{
	// TODO: Add your command handler code here
	fstream f;											// �����ļ�����
	CClientDC dc(this);									// ����ǰ��ͼ��������豸ʵ��
	CEmployeeType e;									// ����Ա������
	char buf[180];										// �����ַ�����
	int n = 0;											// �������
	
	f.open("employee.dat", ios::in | ios::binary);		// �����뷽ʽ���ļ�
	if (f.fail())	
	{	// ���ļ�ʧ��
		cout << "���ļ�ʧ��!" << endl;
		exit(2);										// �˳�����
	}
	
	sprintf(buf, "%13s%25s%10s%18s%20s", "���", "����", "�Ա�", "����", "��������");	// Ա����Ϣ
	dc.TextOut(60, 80 + 20 * n, buf);					// ���Ա����Ϣ
	n++;
	
	f.read((char *)&e, sizeof(CEmployeeType));			// ���ļ��ж������ݵ�e
	while (!f.eof())
	{
		sprintf(buf, "%13s%21s%8s%10d��%02d��%02d�� %10.2f", e.num, e.name, e.sex, e.birthday.year, e.birthday.month, e.birthday.day, e.basicSalary);	// Ա����Ϣ
		dc.TextOut(60, 80 + 20 * n, buf);				// ���Ա����Ϣ
		n++;											// n�Լ�1
		f.read((char *)&e, sizeof(CEmployeeType));		// ���ļ��ж������ݵ�x
	}
	cout << endl;										// ����
	f.close();											// �ر��ļ�
}

void CEmployeeView::OnMenuitemInput() 
{
	// TODO: Add your command handler code here
	fstream f;											// �����ļ�����
	f.open("employee.dat", ios::out | ios::binary);		// �������ʽ���ļ�
	if (f.fail())	
	{	// ���ļ�ʧ��
		cout << "���ļ�ʧ��!" << endl;
		exit(1);										// �˳�����
	}

	do
	{
		CEmployeeDialog dia;							// ����Ի������
		int iResult = dia.DoModal();					// ��ʾ�Ի���

		if (iResult == IDOK)
		{	//�û�����ȷ����ť����
			CEmployeeType e((LPSTR)(LPCTSTR)dia.m_num, (LPSTR)(LPCTSTR)dia.m_name, (LPSTR)(LPCTSTR)dia.m_sex, dia.m_year, dia.m_month, dia.m_day, dia.m_basicSalary);
				// ����Ա������, (LPSTR)(LPCTSTR)����ǿ�ƽ�CString��ת��Ϊchar *��
			f.write((char *)&e, sizeof(CEmployeeType));	// д���ݵ��ļ���
		}
	} while (IDYES == MessageBox("�Ƿ��������Ա����Ϣ?", "��Ϣ��ʾ��", MB_YESNO | MB_ICONQUESTION));
	f.close();											// �ر��ļ�
}
