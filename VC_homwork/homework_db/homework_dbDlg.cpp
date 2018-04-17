
// homework_dbDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "homework_db.h"
#include "homework_dbDlg.h"
#include "afxdialogex.h"
#include "ADO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Chomework_dbDlg �Ի���



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


// Chomework_dbDlg ��Ϣ�������

BOOL Chomework_dbDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Chomework_dbDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Chomework_dbDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Chomework_dbDlg::OnBnClickedOk()
{
	// ��ѯ����
	ado->getRecord("SELECT * FROM mqtt_test");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ado->m_msg);
}


void Chomework_dbDlg::ShowMsg(CString str)
{
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
}


void Chomework_dbDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ado = new daoOption();
}




void Chomework_dbDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	delete ado;
	CDialogEx::OnCancel();
}


void Chomework_dbDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString id="",temp="";
	GetDlgItem(IDC_EDIT5)->GetWindowText(id);
	GetDlgItem(IDC_EDIT6)->GetWindowText(temp);
	ado->deleteData(id,temp);
}
