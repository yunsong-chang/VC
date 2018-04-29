
// DlgProxy.cpp : 实现文件
//

#include "stdafx.h"
#include "ThreadTest.h"
#include "DlgProxy.h"
#include "ThreadTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThreadTestDlgAutoProxy

IMPLEMENT_DYNCREATE(CThreadTestDlgAutoProxy, CCmdTarget)

CThreadTestDlgAutoProxy::CThreadTestDlgAutoProxy()
{
	EnableAutomation();
	
	// 为使应用程序在自动化对象处于活动状态时一直保持 
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CThreadTestDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CThreadTestDlg)))
		{
			m_pDialog = reinterpret_cast<CThreadTestDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CThreadTestDlgAutoProxy::~CThreadTestDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CThreadTestDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CThreadTestDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CThreadTestDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IThreadTest 的支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {00766A2F-1623-4D44-964D-9A885F70057B}
static const IID IID_IThreadTest =
{ 0x766A2F, 0x1623, 0x4D44, { 0x96, 0x4D, 0x9A, 0x88, 0x5F, 0x70, 0x5, 0x7B } };

BEGIN_INTERFACE_MAP(CThreadTestDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CThreadTestDlgAutoProxy, IID_IThreadTest, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏在此项目的 StdAfx.h 中定义
// {A3EA9976-1C41-43F7-B793-FD5953D9BECB}
IMPLEMENT_OLECREATE2(CThreadTestDlgAutoProxy, "ThreadTest.Application", 0xa3ea9976, 0x1c41, 0x43f7, 0xb7, 0x93, 0xfd, 0x59, 0x53, 0xd9, 0xbe, 0xcb)


// CThreadTestDlgAutoProxy 消息处理程序
