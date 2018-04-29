
// DlgProxy.cpp : ʵ���ļ�
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
	
	// ΪʹӦ�ó������Զ��������ڻ״̬ʱһֱ���� 
	//	���У����캯������ AfxOleLockApp��
	AfxOleLockApp();

	// ͨ��Ӧ�ó����������ָ��
	//  �����ʶԻ������ô�����ڲ�ָ��
	//  ָ��Ի��򣬲����öԻ���ĺ���ָ��ָ��
	//  �ô���
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
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	// 	������������ AfxOleUnlockApp��
	//  ���������������⣬�⻹���������Ի���
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CThreadTestDlgAutoProxy::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CThreadTestDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CThreadTestDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_IThreadTest ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {00766A2F-1623-4D44-964D-9A885F70057B}
static const IID IID_IThreadTest =
{ 0x766A2F, 0x1623, 0x4D44, { 0x96, 0x4D, 0x9A, 0x88, 0x5F, 0x70, 0x5, 0x7B } };

BEGIN_INTERFACE_MAP(CThreadTestDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CThreadTestDlgAutoProxy, IID_IThreadTest, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ���ڴ���Ŀ�� StdAfx.h �ж���
// {A3EA9976-1C41-43F7-B793-FD5953D9BECB}
IMPLEMENT_OLECREATE2(CThreadTestDlgAutoProxy, "ThreadTest.Application", 0xa3ea9976, 0x1c41, 0x43f7, 0xb7, 0x93, 0xfd, 0x59, 0x53, 0xd9, 0xbe, 0xcb)


// CThreadTestDlgAutoProxy ��Ϣ�������
