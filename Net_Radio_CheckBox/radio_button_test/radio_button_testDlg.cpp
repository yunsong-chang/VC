
// radio_button_testDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "radio_button_test.h"
#include "radio_button_testDlg.h"
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


// Cradio_button_testDlg �Ի���




Cradio_button_testDlg::Cradio_button_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cradio_button_testDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cradio_button_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK5, m_check5);
	DDX_Control(pDX, IDC_CHECK6, m_check6);
}

BEGIN_MESSAGE_MAP(Cradio_button_testDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PORTAL_RADIO, &Cradio_button_testDlg::OnBnClickedPortalRadio)
	ON_BN_CLICKED(IDC_FORUM_RADIO, &Cradio_button_testDlg::OnBnClickedForumRadio)
	ON_BN_CLICKED(IDC_BLOG_RADIO, &Cradio_button_testDlg::OnBnClickedBlogRadio)
	ON_BN_CLICKED(IDOK, &Cradio_button_testDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Cradio_button_testDlg ��Ϣ�������

BOOL Cradio_button_testDlg::OnInitDialog()
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

void Cradio_button_testDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cradio_button_testDlg::OnPaint()
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
HCURSOR Cradio_button_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cradio_button_testDlg::OnBnClickedPortalRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������;
	InitAllCheckBoxStatus();    
	m_check2.EnableWindow(TRUE);    
	m_check5.EnableWindow(TRUE);    

}


void Cradio_button_testDlg::OnBnClickedForumRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������;
	InitAllCheckBoxStatus();    
	m_check3.EnableWindow(TRUE);    
	m_check6.EnableWindow(TRUE);    

}


void Cradio_button_testDlg::OnBnClickedBlogRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������;
	InitAllCheckBoxStatus();    
	m_check1.EnableWindow(TRUE);    
	m_check4.EnableWindow(TRUE);    
}

void Cradio_button_testDlg::InitAllCheckBoxStatus()    
{    
	// ȫ������;    
	/*m_check1.EnableWindow(FALSE);    
	m_check2.EnableWindow(FALSE);    
	m_check3.EnableWindow(FALSE);    
	m_check4.EnableWindow(FALSE);    
	m_check5.EnableWindow(FALSE);    
	m_check6.EnableWindow(FALSE);    */

	// ȫ����ѡ��    
	m_check1.SetCheck(0);    
	m_check2.SetCheck(0);    
	m_check3.SetCheck(0);    
	m_check4.SetCheck(0);    
	m_check5.SetCheck(0);    
	m_check6.SetCheck(0);    
}  



void Cradio_button_testDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������;
	//CDialogEx::OnOK();
	CString strWebsiteSel;         // ѡ�����վ ;   

	// ��ѡ�С������ס�����������ַ���  ;  
	if (1 == m_check1.GetCheck())    
	{    
		strWebsiteSel += _T("�Ա� ");    
	}    
	// ��ѡ�С����ˡ�����������ַ��� ;   
	if (1 == m_check2.GetCheck())    
	{    
		strWebsiteSel += _T("���� ");    
	}    
	// ��ѡ�С�������̳������������ַ���  ;  
	if (1 == m_check3.GetCheck())    
	{    
		strWebsiteSel += _T("���� ");    
	}    
	// ��ѡ�С��������͡�����������ַ���;    
	if (1 == m_check4.GetCheck())    
	{    
		strWebsiteSel += _T("���� ");    
	}    
	// ��ѡ�С����ס�����������ַ���    
	if (1 == m_check5.GetCheck())    
	{    
		strWebsiteSel += _T("�����");    
	}    
	// ��ѡ�С��������̳������������ַ���;    
	if (1 == m_check6.GetCheck())    
	{    
		strWebsiteSel += _T("������");    
	}    

	// ������ַ�����ʾ�ڡ�ѡ�����վ����ı༭����;    
	SetDlgItemText(IDC_EDIT1, strWebsiteSel);    

	// Ϊ�˱���㡰ȷ������Ի����˳�����OnOkע��;    
	//CDialogEx::OnOK();    

}
