
// radio_button_test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cradio_button_testApp:
// �йش����ʵ�֣������ radio_button_test.cpp
//

class Cradio_button_testApp : public CWinApp
{
public:
	Cradio_button_testApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cradio_button_testApp theApp;