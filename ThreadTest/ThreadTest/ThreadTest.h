
// ThreadTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CThreadTestApp:
// �йش����ʵ�֣������ ThreadTest.cpp
//

class CThreadTestApp : public CWinApp
{
public:
	CThreadTestApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CThreadTestApp theApp;