
// My_Radio.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy_RadioApp:
// �йش����ʵ�֣������ My_Radio.cpp
//

class CMy_RadioApp : public CWinApp
{
public:
	CMy_RadioApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy_RadioApp theApp;