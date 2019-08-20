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
	m_isFocusingNow = true;
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
	ON_BN_KILLFOCUS(ID_BUTTON_INSERT, &CUserInsertDlg::OnBnKillfocusButtonInsert)
	ON_BN_SETFOCUS(ID_BUTTON_INSERT, &CUserInsertDlg::OnBnSetfocusButtonInsert)
END_MESSAGE_MAP()


// CUserInsertDlg 메시지 처리기


void CUserInsertDlg::OnBnClickedButtonInsert()
{
	m_pMainDlg = dynamic_cast<CmfcBasicDlg*>(GetParent());
	if (!m_pMainDlg)
		ASSERT(0);

	const auto& pUserManager = m_pMainDlg->GetPointerUserManager();
	const auto& selectedIndexOnMenu = m_pMainDlg->GetSeletedIndexOnMenuInMfcBasicDlg();
	const auto& userId = m_pMainDlg->GetUserIdIntegerInMfcBasicDlg();

	CString strName = _T(""); 
	CString strPhoneNumber = _T("");
	CString strPosition = _T("");
	CString strTeam = _T("");

	m_insertName.GetWindowText(strName);
	m_insertPhoneNo.GetWindowText(strPhoneNumber);
	m_insertPosition.GetWindowText(strPosition);
	m_insertTeam.GetWindowText(strTeam);
	
	std::shared_ptr<User> newUser = std::make_shared<User>(strName, strPhoneNumber, strPosition, strTeam);

	if (!IsWrittenAllOfElementsForInsert(newUser))
	{
		MessageBox(TEXT("모든정보를 입력해주세요"));
		m_isFocusingNow = false;
	}
	else
	{
		if (selectedIndexOnMenu == 0)
		{
			pUserManager->AssignMemoryAndInsertUserInformation(newUser);
			MessageBox(TEXT("추가되었습니다."));
		}
		else if (selectedIndexOnMenu == 1)
		{
			if (pUserManager->UpdateUserInformation(userId, newUser))
			{
				MessageBox(TEXT("변경되었습니다."));
			}
			else
			{
				MessageBox(TEXT("변경 실패하였습니다."));
			}
		}

		m_pMainDlg->ResettingViewList();
		CUserInsertDlg::EndDialog(0);
		m_isFocusingNow = true;
	}
}

// focus
// 양쪽에 -> 부모 다이얼( ) return false; -> 차일드로 전달 ()

bool CUserInsertDlg::IsWrittenAllOfElementsForInsert(std::shared_ptr<User> newUser)
{		
	const auto& userName = newUser->GetUserName();
	const auto& userPhoneNumber = newUser->GetUserPhoneNumber();
	const auto& userPosition = newUser->GetUserPosition();
	const auto& userTeam = newUser->GetUserTeam();

	if (userName.IsEmpty() || (userName.Find(_T(" ")) >= 0 ))
	{
		return false; 
	}
	if (userPhoneNumber.IsEmpty() || (userPhoneNumber.Find(_T(" ")) >= 0))
	{
		return false; 
	}

	if (userPosition.IsEmpty() || (userPosition.Find(_T(" ")) >= 0))
	{ 
		return false; 
	}
	if (userTeam.IsEmpty() || (userTeam.Find(_T(" ")) >= 0))
	{
		return false; 
	}

	return true;
	
}

BOOL CUserInsertDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->wParam == VK_RETURN && m_isFocusingNow)
	{
		OnBnClickedButtonInsert();
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CUserInsertDlg::OnBnKillfocusButtonInsert()
{
	m_isFocusingNow = false;
}


void CUserInsertDlg::OnBnSetfocusButtonInsert()
{
	m_isFocusingNow = true;
}
