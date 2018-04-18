// employeeView.cpp : implementation of the CEmployeeView class
//

#include "stdafx.h"
#include "employee.h"
#include "EmployeeDialog.h"				// 员工信息对话框
#include <iostream>               		// 编译预处理命令
#include <fstream>               		// 编译预处理命令
using namespace std;					// 使用命名空间std 

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
	fstream f;											// 定义文件对象
	CClientDC dc(this);									// 将当前视图对象定义成设备实例
	CEmployeeType e;									// 定义员工对象
	char buf[180];										// 定义字符数组
	int n = 0;											// 定义变量
	
	f.open("employee.dat", ios::in | ios::binary);		// 以输入方式打开文件
	if (f.fail())	
	{	// 打开文件失败
		cout << "打开文件失败!" << endl;
		exit(2);										// 退出程序
	}
	
	sprintf(buf, "%13s%25s%10s%18s%20s", "编号", "姓名", "性别", "日生", "基本工资");	// 员工信息
	dc.TextOut(60, 80 + 20 * n, buf);					// 输出员工信息
	n++;
	
	f.read((char *)&e, sizeof(CEmployeeType));			// 从文件中读出数据到e
	while (!f.eof())
	{
		sprintf(buf, "%13s%21s%8s%10d年%02d月%02d日 %10.2f", e.num, e.name, e.sex, e.birthday.year, e.birthday.month, e.birthday.day, e.basicSalary);	// 员工信息
		dc.TextOut(60, 80 + 20 * n, buf);				// 输出员工信息
		n++;											// n自加1
		f.read((char *)&e, sizeof(CEmployeeType));		// 从文件中读出数据到x
	}
	cout << endl;										// 换行
	f.close();											// 关闭文件
}

void CEmployeeView::OnMenuitemInput() 
{
	// TODO: Add your command handler code here
	fstream f;											// 定义文件对象
	f.open("employee.dat", ios::out | ios::binary);		// 以输出方式打开文件
	if (f.fail())	
	{	// 打开文件失败
		cout << "打开文件失败!" << endl;
		exit(1);										// 退出程序
	}

	do
	{
		CEmployeeDialog dia;							// 定义对话框对象
		int iResult = dia.DoModal();					// 显示对话框

		if (iResult == IDOK)
		{	//用户单击确定按钮返回
			CEmployeeType e((LPSTR)(LPCTSTR)dia.m_num, (LPSTR)(LPCTSTR)dia.m_name, (LPSTR)(LPCTSTR)dia.m_sex, dia.m_year, dia.m_month, dia.m_day, dia.m_basicSalary);
				// 定义员工对象, (LPSTR)(LPCTSTR)用于强制将CString型转换为char *型
			f.write((char *)&e, sizeof(CEmployeeType));	// 写数据到文件中
		}
	} while (IDYES == MessageBox("是否继续输入员工信息?", "信息提示框", MB_YESNO | MB_ICONQUESTION));
	f.close();											// 关闭文件
}
