
// homework_dbDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "homework_db.h"
#include "homework_dbDlg.h"
#include "afxdialogex.h"
#include "ADO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Chomework_dbDlg 对话框



Chomework_dbDlg::Chomework_dbDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Chomework_dbDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Chomework_dbDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(Chomework_dbDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Chomework_dbDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &Chomework_dbDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &Chomework_dbDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &Chomework_dbDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Chomework_dbDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Chomework_dbDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// Chomework_dbDlg 消息处理程序

BOOL Chomework_dbDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Chomework_dbDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Chomework_dbDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Chomework_dbDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Chomework_dbDlg::OnBnClickedOk()
{
	// 查询操作
	ado->getRecord("SELECT * FROM mqtt_test");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ado->m_msg);
}


void Chomework_dbDlg::ShowMsg(CString str)
{
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
}


void Chomework_dbDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ado = new daoOption();
}




void Chomework_dbDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	delete ado;
	CDialogEx::OnCancel();
}


void Chomework_dbDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	ado->putRecord(str);
}


void Chomework_dbDlg::OnBnClickedButton4()
{
	CString str,str1;
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	GetDlgItem(IDC_EDIT4)->GetWindowText(str1);
	ado->updateRecord(str, str1);
}


void Chomework_dbDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString id="",temp="";
	GetDlgItem(IDC_EDIT5)->GetWindowText(id);
	GetDlgItem(IDC_EDIT6)->GetWindowText(temp);
	ado->deleteData(id,temp);
}
