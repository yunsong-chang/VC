
// SilderControl.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSilderCtlApp:
// �йش����ʵ�֣������ SilderControl.cpp
//

class CSilderCtlApp : public CWinApp
{
public:
	CSilderCtlApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSilderCtlApp theApp;