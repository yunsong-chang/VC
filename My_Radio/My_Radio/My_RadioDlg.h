
// My_RadioDlg.h : 头文件
//

#pragma once


// CMy_RadioDlg 对话框
class CMy_RadioDlg : public CDialogEx
{
// 构造
public:
	CMy_RadioDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_RADIO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_BtnRadioGroup1;
	int m_BtnRadioGroup2;
	afx_msg void OnBnClickedRadioGroup1();
	afx_msg void OnBnClickedRadioGroup2();
	afx_msg void OnBnClickedBtncheck();
};
