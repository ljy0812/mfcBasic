// CUserInsertDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "mfcBasic.h"
#include "CUserInsertDlg.h"
#include "afxdialogex.h"
#include "mfcBasicDlg.h"

// CUserInsertDlg 대화 상자

IMPLEMENT_DYNAMIC(CUserInsertDlg, CDialogEx)

CUserInsertDlg::CUserInsertDlg(CmfcBasicDlg* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INSERT, pParent)
{
	m_pMainDlg = pParent;
}

CUserInsertDlg::~CUserInsertDlg()
{
}

void CUserInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INSERT_NAME, m_insertName);
	DDX_Control(pDX, IDC_INSERT_POSITION, m_insertPosition);
	DDX_Control(pDX, IDC_INSERT_TEAM, m_insertTeam);
	DDX_Control(pDX, ID_BUTTON_INSERT, m_insertButton);
	DDX_Control(pDX, IDC_INSERT_PHONE_NO, m_insertPhoneNo);
}


BEGIN_MESSAGE_MAP(CUserInsertDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_INSERT, &CUserInsertDlg::OnBnClickedButtonInsert)
END_MESSAGE_MAP()


// CUserInsertDlg 메시지 처리기


void CUserInsertDlg::OnBnClickedButtonInsert()
{
	CString strName, strPhoneNo, strPosition, strTeam;
	m_insertName.GetWindowTextW(strName);
	m_insertPhoneNo.GetWindowTextW(strPhoneNo);
	m_insertPosition.GetWindowTextW(strPosition);
	m_insertTeam.GetWindowTextW(strTeam);
	
	std::shared_ptr<User> newUser = std::make_shared<User>(strName, strPhoneNo, strPosition, strTeam);

	if (!IsWrittenAllOfElementsForInsert(newUser))
	{
		MessageBox(TEXT("모든정보를 입력해주세요"));
	}
	else
	{
		if (((CmfcBasicDlg*)GetParent())->selectedIndexOnMenu == 0)
		{
			((CmfcBasicDlg*)GetParent())->m_pUserManager->AssignMemoryAndInsertUserInformation(newUser);	
			MessageBox(TEXT("추가되었습니다."));
		
		}
		else if (((CmfcBasicDlg*)GetParent())->selectedIndexOnMenu == 1)
		{
			((CmfcBasicDlg*)GetParent())->m_pUserManager->UpdateUserInformation(((CmfcBasicDlg*)GetParent())->selectedIndexOnUserList, newUser);
			MessageBox(TEXT("변경되었습니다."));
		}

		((CmfcBasicDlg*)GetParent())->ResettingViewList();
		CUserInsertDlg::EndDialog(0);
	}
	
}

bool CUserInsertDlg::IsWrittenAllOfElementsForInsert(std::shared_ptr<User> newUser)
{
	CString str;
	
	str = newUser->GetUserName();
	if (str.IsEmpty() || (str.Find(_T(" ")) >= 0 ))
	{
		return false; 
	}

	str = newUser->GetUserPosition();
	if (str.IsEmpty() || (str.Find(_T(" ")) >= 0))
	{
		return false; 
	}

	str = newUser->GetUserTeam();
	if (str.IsEmpty() || (str.Find(_T(" ")) >= 0))
	{ 
		return false; 
	}
	str = newUser->GetUserPhoneNo();
	if (str.IsEmpty() || (str.Find(_T(" ")) >= 0))
	{
		return false; 
	}

	return true;
	
}
