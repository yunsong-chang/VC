
// My_RadioDlg.h : ͷ�ļ�
//

#pragma once


// CMy_RadioDlg �Ի���
class CMy_RadioDlg : public CDialogEx
{
// ����
public:
	CMy_RadioDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_RADIO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
