
// ThreadTestDlg.h : 头文件
//

#pragma once

class CThreadTestDlgAutoProxy;


// CThreadTestDlg 对话框
class CThreadTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CThreadTestDlg);
	friend class CThreadTestDlgAutoProxy;

// 构造
public:
	CThreadTestDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CThreadTestDlg();

// 对话框数据
	enum { IDD = IDD_THREADTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CThreadTestDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
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
