
// mfcBasic.cpp: 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "mfcBasic.h"
#include "mfcBasicDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcBasicApp

BEGIN_MESSAGE_MAP(CmfcBasicApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CmfcBasicApp 생성

CmfcBasicApp::CmfcBasicApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CmfcBasicApp 개체입니다.

CmfcBasicApp theApp;


// CmfcBasicApp 초기화

BOOL CmfcBasicApp::InitInstance()
{
	CWinApp::InitInstance();

	CmfcBasicDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}

