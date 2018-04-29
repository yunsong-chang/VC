// CmySilderCtl.cpp : 实现文件

#include "stdafx.h"
#include "SilderControl.h"
#include "CmySilderCtl.h"
#include "SilderCtlDlg.h"


// CmySilderCtl

IMPLEMENT_DYNAMIC(CmySilderCtl, CSliderCtrl)

CmySilderCtl::CmySilderCtl()
{
	m_dcBk.m_hDC = NULL;
}

CmySilderCtl::~CmySilderCtl()
{
	DeleteObject(m_dcBk.SelectObject(&m_bmpBkOld/*m_pbmBkOld*/)); //删除新的bitmap对象
	DeleteDC(m_dcBk);
}


BEGIN_MESSAGE_MAP(CmySilderCtl, CSliderCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CmySilderCtl::OnNMCustomdraw)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CmySilderCtl 消息处理程序
//
void CmySilderCtl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
// 	m_sidlerValue = GetPos();
// 	SendMessageA(GetParent()->m_hWnd,WM_USER + 4,0,m_sidlerValue);

	LPNMCUSTOMDRAW lpcd = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CDC *pDC = CDC::FromHandle(lpcd->hdc);
	switch(lpcd->dwDrawStage)
	{
	case CDDS_PREPAINT:
		*pResult = CDRF_NOTIFYITEMDRAW;
		break;
	case CDDS_ITEMPREPAINT:
		if(lpcd->dwItemSpec == TBCD_THUMB)
		{
			 	m_sidlerValue = GetPos();
			 	SendMessageA(GetParent()->m_hWnd,WM_USER + 4,0,m_sidlerValue);
			*pResult = CDRF_DODEFAULT;
			break;
		}
		if(lpcd->dwItemSpec == TBCD_CHANNEL)
		{
			CClientDC clientDC (GetParent());
			CRect crect;
			CRect wrect;
			GetClientRect(/*&crect*/crect);
			GetWindowRect(/*&*/wrect);
			GetParent()->ScreenToClient(/*&*/wrect);
			if(m_dcBk.m_hDC == NULL)
			{
				m_dcBk.CreateCompatibleDC(&clientDC);
				m_bmpBk.CreateCompatibleBitmap(&clientDC,crect.Width(),crect.Height());
				/*m_pbmBkOld*/m_bmpBkOld = m_dcBk.SelectObject(&m_bmpBk);
				m_dcBk.BitBlt(0,0,crect.Width(),crect.Height(),&clientDC,wrect.left,wrect.top,SRCCOPY);
			}
			//This bit does the tics marks transparently
			CDC SaveCDC;
			CBitmap  SaveCBmp,maskBitmap;
			//set the colours for the monochrome mask bitmap
			COLORREF crOldBack = pDC->SetBkColor(RGB(0,0,0));
			COLORREF crOldText = pDC->SetTextColor(RGB(255,255,255));
			CDC maskDC;
			int iWidth = crect.Width();
			int iHeight = crect.Height();
			 SaveCDC.CreateCompatibleDC(pDC);  //my
			SaveCBmp.CreateCompatibleBitmap(&SaveCDC,iWidth,iHeight);
			CBitmap *SaveCBmpOld = (CBitmap*)SaveCDC.SelectObject(SaveCBmp);
			//fill in the memroy dc for the mask 
			maskDC.CreateCompatibleDC(&SaveCDC);
			//create a monochrome bitmap
			maskBitmap.CreateBitmap(iWidth,iHeight,1,1,NULL);
			//select the mask bitmap into the dc
			CBitmap *OldmaskBitmap = maskDC.SelectObject(&maskBitmap);
			//copy the oldbitmap data into the bitmap,this includes the tics.
			SaveCDC.BitBlt(0,0,iWidth,iHeight,pDC,crect.left,crect.top,SRCCOPY);
			
			//now copy the background into the slider
			BitBlt(lpcd->hdc,0,0,iWidth,iHeight,m_dcBk.m_hDC,0,0,SRCCOPY);
			//blit the mask based on background colour
			maskDC.BitBlt(0,0,iWidth,iHeight,&SaveCDC,0,0,SRCCOPY);
			//Blit the image using the mask
			pDC->BitBlt(0,0,iWidth,iHeight,&SaveCDC,0,0,SRCINVERT);
			pDC->BitBlt(0,0,iWidth,iHeight,&maskDC,0,0,SRCAND);
			pDC->BitBlt(0,0,iWidth,iHeight,&SaveCDC,0,0,SRCINVERT);

			//resource and clean up
			pDC->SetBkColor(crOldBack);
			pDC->SetTextColor(crOldText);
			DeleteObject(SelectObject(SaveCDC,SaveCBmpOld));  //删除新的bitmap对象选入原bitmap对象
			DeleteDC(SaveCDC);

			DeleteObject(maskDC.SelectObject(OldmaskBitmap));
			DeleteDC(maskDC);
			*pResult = 0;
			break;
		}
	}
	//*pResult = 0;
}


BOOL CmySilderCtl::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return FALSE;
	//return CSliderCtrl::OnEraseBkgnd(pDC);
}

