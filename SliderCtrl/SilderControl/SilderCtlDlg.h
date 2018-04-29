
// SilderCtlDlg.h : ͷ�ļ�
//

#pragma once
#include "CmySilderCtl.h"

// CSilderCtlDlg �Ի���
class CSilderCtlDlg : public CDialogEx
{
// ����
public:
	CSilderCtlDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SILDERCONTROL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
