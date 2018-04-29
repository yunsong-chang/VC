// SilderCtlDlg.cpp : ʵ���ļ�

#include "stdafx.h"
#include "SilderControl.h"
#include "SilderCtlDlg.h"
#include "afxdialogex.h"
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSilderCtlDlg �Ի���

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


// CSilderCtlDlg ��Ϣ�������

BOOL CSilderCtlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
 
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	onsizefirst = TRUE;
	m_mySlider.SetPos(30);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSilderCtlDlg::OnPaint()
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
//<�ر����ѣ�>����ͼƬ������ȥ��ͬʱ�ı䴰��ĳ���ᵼ��silder��Ϣ�����ڴ˲���Picture Control
	//���Ʊ���ͼƬ
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSilderCtlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CSilderCtlDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	switch(pWnd->GetDlgCtrlID())		
	{		
	case IDC_EDIT1:
		{			
			pDC->SetBkMode(TRANSPARENT);//���ñ���Ϊ͸��            			
			pDC->SetTextColor(RGB(255,0,0)); //����������ɫ
			//����Edit�ı���
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

			return brush;//HBRUSH(GetStockObject(HOLLOW_BRUSH)); // ����		������λͼ����ˢ�������͸������	
		}
	case IDC_STATIC:
		{
			pDC->SetBkMode(TRANSPARENT);//���ñ���Ϊ͸��            			
			pDC->SetTextColor(RGB(255,0,0)); //����������ɫ
			return HBRUSH(GetStockObject(HOLLOW_BRUSH)); // ����
		}
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CSilderCtlDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if( onsizefirst == FALSE )
	{
		CRect rect;
		GetDlgItem(IDC_SLIDER1)->GetWindowRect(rect);  //�ڴ���մ���ʱҲ����ô˺�������ʾ�˾���ʳ�ͻ�����ÿ��ؿ��Ʊܿ���һ����ִ�д˾�
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
