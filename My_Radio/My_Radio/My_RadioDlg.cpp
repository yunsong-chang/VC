
// My_RadioDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "My_Radio.h"
#include "My_RadioDlg.h"
#include "afxdialogex.h"

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


// CMy_RadioDlg 对话框




CMy_RadioDlg::CMy_RadioDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy_RadioDlg::IDD, pParent)
	, m_BtnRadioGroup1(0)
	, m_BtnRadioGroup2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy_RadioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_BtnRadioGroup1);
	DDX_Radio(pDX, IDC_RADIO4, m_BtnRadioGroup2);
}

BEGIN_MESSAGE_MAP(CMy_RadioDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CMy_RadioDlg::OnBnClickedRadioGroup1)
	ON_BN_CLICKED(IDC_RADIO2, &CMy_RadioDlg::OnBnClickedRadioGroup1)
	ON_BN_CLICKED(IDC_RADIO3, &CMy_RadioDlg::OnBnClickedRadioGroup1)
	ON_BN_CLICKED(IDC_RADIO4, &CMy_RadioDlg::OnBnClickedRadioGroup2)
	ON_BN_CLICKED(IDC_RADIO5, &CMy_RadioDlg::OnBnClickedRadioGroup2)
	ON_BN_CLICKED(IDC_BtnCheck, &CMy_RadioDlg::OnBnClickedBtncheck)
END_MESSAGE_MAP()


// CMy_RadioDlg 消息处理程序

BOOL CMy_RadioDlg::OnInitDialog()
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

	m_BtnRadioGroup1 = 2;
	m_BtnRadioGroup2 = 1;
	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy_RadioDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy_RadioDlg::OnPaint()
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
HCURSOR CMy_RadioDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy_RadioDlg::OnBnClickedRadioGroup1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	switch (m_BtnRadioGroup1)
	{
	case 0:
		MessageBox(_T("Radio1被选中"));
		break;
	case 1:
		MessageBox(_T("Radio2被选中"));
		break;
	case 2:
		MessageBox(_T("Radio3被选中"));
		break;
	}
}


void CMy_RadioDlg::OnBnClickedRadioGroup2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	switch (m_BtnRadioGroup2)
	{
	case 0:
		MessageBox(_T("Radio4被选中"));
		break;
	case 1:
		MessageBox(_T("Radio5被选中"));
		break;
	}
}


void CMy_RadioDlg::OnBnClickedBtncheck()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck())
	{

	}

	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);

	CButton   *pB; 
	pB=(CButton*)GetDlgItem(IDC_RADIO1); 
	pB->SetCheck(TRUE); 

}
