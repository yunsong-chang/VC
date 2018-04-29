// SilderCtlDlg.cpp : 实现文件

#include "stdafx.h"
#include "SilderControl.h"
#include "SilderCtlDlg.h"
#include "afxdialogex.h"
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSilderCtlDlg 对话框

CSilderCtlDlg::CSilderCtlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSilderCtlDlg::IDD, pParent)
	, m_sildVal(_T("30"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSilderCtlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_mySlider);
	DDX_Text(pDX, IDC_EDIT1, m_sildVal);
}

BEGIN_MESSAGE_MAP(CSilderCtlDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_MESSAGE(WM_USER + 4, &CSilderCtlDlg::OnGetSilderVal)
END_MESSAGE_MAP()


// CSilderCtlDlg 消息处理程序

BOOL CSilderCtlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
 
	// TODO: 在此添加额外的初始化代码
	onsizefirst = TRUE;
	m_mySlider.SetPos(30);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSilderCtlDlg::OnPaint()
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
//<特别提醒：>背景图片绘制上去后，同时改变窗体的长宽会导致silder消息，故在此采用Picture Control
	//绘制背景图片
	CRect rect;
	GetClientRect(&rect);
	CDC *pDC = GetDC();
	CDC memdc;
	memdc.CreateCompatibleDC(pDC);
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BMPBK);
	memdc.SelectObject(bitmap);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,SRCCOPY);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSilderCtlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CSilderCtlDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	switch(pWnd->GetDlgCtrlID())		
	{		
	case IDC_EDIT1:
		{			
			pDC->SetBkMode(TRANSPARENT);//设置背景为透明            			
			pDC->SetTextColor(RGB(255,0,0)); //设置字体颜色
			//绘制Edit的背景
			CRect rect,temp;
			CDC *pDC = GetDC();
			CDC memdc;
			memdc.CreateCompatibleDC(pDC);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_BMPBK);
			memdc.SelectObject(bitmap);
			GetDlgItem(IDC_EDIT1)->GetWindowRect(rect);  
			temp = rect;
			ScreenToClient(&rect);
			CBrush brush,*oldBrush;
			brush.CreatePatternBrush(&bitmap);
			oldBrush = pDC->SelectObject(&brush);
			pDC->FillRect(rect,&brush);
			DeleteObject(pDC->SelectObject(oldBrush));

			pDC->BitBlt(107,85,temp.Width(),temp.Height(),&memdc,107,85,SRCCOPY);

			return brush;//HBRUSH(GetStockObject(HOLLOW_BRUSH)); // 必须		可以用位图当画刷解决背景透明问题	
		}
	case IDC_STATIC:
		{
			pDC->SetBkMode(TRANSPARENT);//设置背景为透明            			
			pDC->SetTextColor(RGB(255,0,0)); //设置字体颜色
			return HBRUSH(GetStockObject(HOLLOW_BRUSH)); // 必须
		}
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CSilderCtlDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if( onsizefirst == FALSE )
	{
		CRect rect;
		GetDlgItem(IDC_SLIDER1)->GetWindowRect(rect);  //在窗体刚创建时也会调用此函数，提示此句访问冲突，故用开关控制避开第一调用执行此句
		ScreenToClient(&rect);
		InvalidateRect(&rect,TRUE);   

		GetDlgItem(IDC_STATIC)->GetWindowRect(rect);  
		ScreenToClient(&rect);
		InvalidateRect(&rect,TRUE);

		GetDlgItem(IDC_EDIT1)->GetWindowRect(rect);  
		ScreenToClient(&rect);
		InvalidateRect(&rect,TRUE);
	}
	onsizefirst = FALSE;
}


afx_msg LRESULT CSilderCtlDlg::OnGetSilderVal(WPARAM wParam, LPARAM lParam)
{
	m_sildVal.Format(_T("%d%%"),lParam);
	UpdateData(FALSE);
	return 0;
}
