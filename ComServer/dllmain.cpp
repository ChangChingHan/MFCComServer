// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "ComServer_i.h"
#include "dllmain.h"
#include "dlldatax.h"

CComServerModule _AtlModule;

class CComServerApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CComServerApp, CWinApp)
END_MESSAGE_MAP()

CComServerApp theApp;

BOOL CComServerApp::InitInstance()
{
#ifdef _MERGE_PROXYSTUB
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, NULL))
		return FALSE;
#endif
	return CWinApp::InitInstance();
}

int CComServerApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
