
// SilderCtlDlg.h : 头文件
//

#pragma once
#include "CmySilderCtl.h"

// CSilderCtlDlg 对话框
class CSilderCtlDlg : public CDialogEx
{
// 构造
public:
	CSilderCtlDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SILDERCONTROL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CmySilderCtl m_mySlider;
	BOOL onsizefirst;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	CString m_sildVal;

protected:
	afx_msg LRESULT OnGetSilderVal(WPARAM wParam, LPARAM lParam);
};
