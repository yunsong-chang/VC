#pragma once


// CmySilderCtl

class CmySilderCtl : public CSliderCtrl
{
	DECLARE_DYNAMIC(CmySilderCtl)

public:
	CmySilderCtl();
	virtual ~CmySilderCtl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);

private:
	CDC m_dcBk;
	CBitmap m_bmpBk;
	//CBitmap *m_pbmBkOld;
	CBitmap *m_bmpBkOld;
	CPen m_penThumb;
	CPen m_penThumbLight;
	CPen m_penThumbLighter;
	CPen m_penThumbDark;
	CPen m_penThumbDarker;
	COLORREF m_crThumb;
	COLORREF m_crThumbLight;
	COLORREF m_crThumbLighter;
	COLORREF m_crThumbDark;
	COLORREF m_crThumbDarker;
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSizeClipboard(CWnd* pClipAppWnd, HGLOBAL hRect);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);

	int m_sidlerValue;
};


