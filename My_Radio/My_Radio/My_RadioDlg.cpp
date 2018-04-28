
// My_RadioDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "My_Radio.h"
#include "My_RadioDlg.h"
#include "afxdialogex.h"

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


// CMy_RadioDlg �Ի���




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


// CMy_RadioDlg ��Ϣ�������

BOOL CMy_RadioDlg::OnInitDialog()
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

	m_BtnRadioGroup1 = 2;
	m_BtnRadioGroup2 = 1;
	UpdateData(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy_RadioDlg::OnPaint()
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
HCURSOR CMy_RadioDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy_RadioDlg::OnBnClickedRadioGroup1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	switch (m_BtnRadioGroup1)
	{
	case 0:
		MessageBox(_T("Radio1��ѡ��"));
		break;
	case 1:
		MessageBox(_T("Radio2��ѡ��"));
		break;
	case 2:
		MessageBox(_T("Radio3��ѡ��"));
		break;
	}
}


void CMy_RadioDlg::OnBnClickedRadioGroup2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	switch (m_BtnRadioGroup2)
	{
	case 0:
		MessageBox(_T("Radio4��ѡ��"));
		break;
	case 1:
		MessageBox(_T("Radio5��ѡ��"));
		break;
	}
}


void CMy_RadioDlg::OnBnClickedBtncheck()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck())
	{

	}

	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);

	CButton   *pB; 
	pB=(CButton*)GetDlgItem(IDC_RADIO1); 
	pB->SetCheck(TRUE); 

}
