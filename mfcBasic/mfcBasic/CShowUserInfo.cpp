// CShowUserInfo.cpp: 구현 파일
//

#include "stdafx.h"
#include "mfcBasic.h"
#include "CShowUserInfo.h"
#include "afxdialogex.h"


// CShowUserInfo 대화 상자

IMPLEMENT_DYNAMIC(CShowUserInfo, CDialogEx)

CShowUserInfo::CShowUserInfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SHOW_INFO, pParent)
{

}

CShowUserInfo::~CShowUserInfo()
{
}



void CShowUserInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW_NO, m_showNo);
	DDX_Control(pDX, IDC_SHOW_NAME, m_showName);
	DDX_Control(pDX, IDC_SHOW_PHONE_NO, m_showPhoneNo);
	DDX_Control(pDX, IDC_SHOW_POSITION, m_showPosition);
	DDX_Control(pDX, IDC_SHOW_TEAM, m_showTeam);
	DDX_Control(pDX, IDC_PHOTO, m_showPhoto);
}


BEGIN_MESSAGE_MAP(CShowUserInfo, CDialogEx)
END_MESSAGE_MAP()


// CShowUserInfo 메시지 처리기




