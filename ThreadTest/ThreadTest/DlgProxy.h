
// DlgProxy.h: ͷ�ļ�
//

#pragma once

class CThreadTestDlg;


// CThreadTestDlgAutoProxy ����Ŀ��

class CThreadTestDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CThreadTestDlgAutoProxy)

	CThreadTestDlgAutoProxy();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��

// ����
public:
	CThreadTestDlg* m_pDialog;

// ����
public:

// ��д
	public:
	virtual void OnFinalRelease();

// ʵ��
protected:
	virtual ~CThreadTestDlgAutoProxy();

	// ���ɵ���Ϣӳ�亯��

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CThreadTestDlgAutoProxy)

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

