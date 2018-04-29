
// ThreadTestDlg.h : ͷ�ļ�
//

#pragma once

class CThreadTestDlgAutoProxy;


// CThreadTestDlg �Ի���
class CThreadTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CThreadTestDlg);
	friend class CThreadTestDlgAutoProxy;

// ����
public:
	CThreadTestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CThreadTestDlg();

// �Ի�������
	enum { IDD = IDD_THREADTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	CThreadTestDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
private:
	CWinThread* m_pMyWinThread;
public:
	afx_msg void OnBnClickedBtnsuspend();
	afx_msg void OnBnClickedBtnresume();
};
