
// mfcBasicDlg.cpp: 구현 파일

#include "stdafx.h"
#include "mfcBasic.h"
#include "mfcBasicDlg.h"
#include "afxdialogex.h"
#include <assert.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcBasicDlg 대화 상자
CmfcBasicDlg::CmfcBasicDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCBASIC_DIALOG, pParent)
{

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pUserManager = std::make_shared<UserManager>();
	m_pUserInsertDlg = std::make_shared<CUserInsertDlg>();
	m_pShowUserInfo = std::make_shared<CShowUserInfo>();
	m_pFileManager = std::make_shared<FileManager>();

	m_selectedIndexOnMenu = -1;
	m_selectedIndexOnUserList = -1;
	m_userIdInteger = -1;


	setlocale(LC_ALL, "korean");
}

void CmfcBasicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_SEARCH, m_searchButton);
	DDX_Control(pDX, IDC_EDIT_SEARCH_ID, m_editSearchById);
	DDX_Control(pDX, IDC_LIST_INDEX, m_indexList);
	DDX_Control(pDX, IDC_LISTCTRL_VIEW, m_viewListCtrl);
}

BEGIN_MESSAGE_MAP(CmfcBasicDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CmfcBasicDlg::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDOK, &CmfcBasicDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CmfcBasicDlg::OnBnClickedCancel)
	ON_NOTIFY(NM_DBLCLK, IDC_LISTCTRL_VIEW, &CmfcBasicDlg::OnNMDblclkListctrlView)
	ON_NOTIFY(NM_CLICK, IDC_LISTCTRL_VIEW, &CmfcBasicDlg::OnNMClickListctrlView)
	ON_LBN_DBLCLK(IDC_LIST_INDEX, &CmfcBasicDlg::OnLbnDblclkListIndex)
END_MESSAGE_MAP()


// CmfcBasicDlg 메시지 처리기

BOOL CmfcBasicDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	SettingIndexList();
	m_pUserInsertDlg->Create(IDD_DIALOG_INSERT, this);
	m_pUserInsertDlg->CenterWindow(this);

	m_pShowUserInfo->Create(IDD_DIALOG_SHOW_INFO, this);
	m_pShowUserInfo->CenterWindow(this);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcBasicDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcBasicDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CmfcBasicDlg::OnBnClickedButtonSearch()
{
	CString userId;
	m_editSearchById.GetWindowTextW(userId);

	const auto& isExistUser = m_pUserManager->SearchUserByUserId(userId);
	if (isExistUser)
	{
		ShowUserInfoDlgByUserId(_ttoi(userId));
	}
	else
	{
		MessageBox(_T("검색 결과가 없습니다."));
	}
}



void CmfcBasicDlg::OnLbnDblclkListIndex()
{
	m_selectedIndexOnMenu = m_indexList.GetCurSel();
	const auto& userId = m_viewListCtrl.GetItemText(m_selectedIndexOnUserList, 0);
	m_userIdInteger = _ttoi(userId);

	if (m_selectedIndexOnMenu == 0)
	{
		MenuAddUser();
	}
	else if (m_selectedIndexOnMenu != 0)
	{
		if (m_selectedIndexOnMenu == 3)
		{
			MenuFileSave();
		}
		else if (m_selectedIndexOnMenu == 4)
		{
			MenuFileLoad();
		}
		else 
		{
			if (m_selectedIndexOnUserList >= 0)
			{
				if (m_selectedIndexOnMenu == 1)
				{
					MenuEditUserInfo(m_userIdInteger);
				}
				else if (m_selectedIndexOnMenu == 2)
				{
					MenuDeleteUser(m_userIdInteger);
				}
			}
			else
			{
				MessageBox(_T("사용자를 선택 후 눌러주세요."));
			}
		}		
		
	}
}

void CmfcBasicDlg::OnBnClickedOk()
{
	CDialogEx::OnOK();
}


void CmfcBasicDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


void CmfcBasicDlg::OnNMDblclkListctrlView(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;

	POSITION pos;
	pos = m_viewListCtrl.GetFirstSelectedItemPosition();
	const auto& index = m_viewListCtrl.GetNextSelectedItem(pos);
	const auto& userId = m_viewListCtrl.GetItemText(index, 0);

	if (index >= 0)
	{
		ShowUserInfoDlgByUserId(_ttoi(userId));
	}
	
}


void CmfcBasicDlg::OnNMClickListctrlView(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;
	
	POSITION pos;
	pos = m_viewListCtrl.GetFirstSelectedItemPosition();
	m_selectedIndexOnUserList = m_viewListCtrl.GetNextSelectedItem(pos);

}

void CmfcBasicDlg::SettingIndexList()
{
	m_indexList.AddString(TEXT("1.추가하기"));
	m_indexList.AddString(TEXT("2.편집하기"));
	m_indexList.AddString(TEXT("3.삭제하기"));
	m_indexList.AddString(TEXT("4.저장하기"));
	m_indexList.AddString(TEXT("5.불러오기"));

	m_viewListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	m_viewListCtrl.InsertColumn(0, _T("번호"), LVCFMT_LEFT, 100, -1);
	m_viewListCtrl.InsertColumn(1, _T("이름"), LVCFMT_LEFT, 100, -1);
	m_viewListCtrl.InsertColumn(2, _T("휴대폰번호"), LVCFMT_LEFT, 100, -1);
	m_viewListCtrl.InsertColumn(3, _T("직함"), LVCFMT_LEFT, 100, -1);
	m_viewListCtrl.InsertColumn(4, _T("부서"), LVCFMT_LEFT, 100, -1);

}

void CmfcBasicDlg::ResettingViewList()
{
	m_viewListCtrl.DeleteAllItems();
	int cnt = 0;
	for (const auto& element : m_pUserManager->GetUserMap())
	{
		m_viewListCtrl.InsertItem(cnt, element.second->GetUserIdConvertedToString());
		m_viewListCtrl.SetItem(cnt, 1, LVIF_TEXT, element.second->GetUserName(), 0, 0, 0, 0);
		m_viewListCtrl.SetItem(cnt, 2, LVIF_TEXT, element.second->GetUserPhoneNumber(), 0, 0, 0, 0);
		m_viewListCtrl.SetItem(cnt, 3, LVIF_TEXT, element.second->GetUserPosition(), 0, 0, 0, 0);
		m_viewListCtrl.SetItem(cnt, 4, LVIF_TEXT, element.second->GetUserTeam(), 0, 0, 0, 0);
		cnt++;
	}
}

void CmfcBasicDlg::ShowUserInfoDlgByUserId(const int& userId)
{
	auto& userMap = m_pUserManager->GetUserMap();

	m_pShowUserInfo->ShowWindow(SW_SHOW);

	m_pShowUserInfo->m_showNo.SetWindowTextW(userMap[userId]->GetUserIdConvertedToString());
	m_pShowUserInfo->m_showName.SetWindowTextW(userMap[userId]->GetUserName());
	m_pShowUserInfo->m_showPhoneNo.SetWindowTextW(userMap[userId]->GetUserPhoneNumber());
	m_pShowUserInfo->m_showPosition.SetWindowTextW(userMap[userId]->GetUserPosition());
	m_pShowUserInfo->m_showTeam.SetWindowTextW(userMap[userId]->GetUserTeam());
}

void CmfcBasicDlg::MenuAddUser()
{
	m_pUserInsertDlg->ShowWindow(SW_SHOW);
	m_pUserInsertDlg->SetWindowTextW(_T("사용자 추가하기"));
	m_pUserInsertDlg->m_insertName.SetWindowTextW(_T(""));
	m_pUserInsertDlg->m_insertPhoneNo.SetWindowTextW(_T(""));
	m_pUserInsertDlg->m_insertPosition.SetWindowTextW(_T(""));
	m_pUserInsertDlg->m_insertTeam.SetWindowTextW(_T(""));
}
void CmfcBasicDlg::MenuEditUserInfo(const int& userId)
{
	auto& userMap = m_pUserManager->GetUserMap();

	m_pUserInsertDlg->ShowWindow(SW_SHOW);
	m_pUserInsertDlg->SetWindowTextW(_T("사용자정보 수정하기"));

	m_pUserInsertDlg->m_insertName.SetWindowTextW(userMap[userId]->GetUserName());
	m_pUserInsertDlg->m_insertPhoneNo.SetWindowTextW(userMap[userId]->GetUserPhoneNumber());
	m_pUserInsertDlg->m_insertPosition.SetWindowTextW(userMap[userId]->GetUserPosition());
	m_pUserInsertDlg->m_insertTeam.SetWindowTextW(userMap[userId]->GetUserTeam());
}
void CmfcBasicDlg::MenuDeleteUser(const int& userId)
{
	
	if (IDYES == AfxMessageBox(_T("삭제하시겠습니까?"), MB_YESNO))
	{
		const auto& isPossibleDelete = m_pUserManager->DeleteUser(userId);
		if (isPossibleDelete)
		{
			AfxMessageBox(_T("삭제완료"));
			ResettingViewList();
		}
		else
		{
			AfxMessageBox(_T("삭제를 완료하지 못했습니다."));
		}
	}
	else if (IDNO)
	{
	}
}


void CmfcBasicDlg::MenuFileSave()
{
	auto isCompleteSave = m_pFileManager->SaveAsCsv(m_pUserManager);
	if (isCompleteSave)
	{
		MessageBox(_T("저장하기완료"));
	}
	else
	{
		MessageBox(_T("저장하기실패"));
	}
}

void CmfcBasicDlg::MenuFileLoad()
{
	auto isCompleteLoad = m_pFileManager->LoadAsCsv(m_pUserManager);
	if (isCompleteLoad)
	{
		ResettingViewList();
		MessageBox(_T("불러오기완료"));

	}
	else
	{
		MessageBox(_T("불러오기실패"));
	}
}

std::shared_ptr<UserManager> CmfcBasicDlg::GetPointerUserManager()
{
	return m_pUserManager;
}

int CmfcBasicDlg::GetSeletedIndexOnMenuInMfcBasicDlg()
{
	return m_selectedIndexOnMenu;
}

int CmfcBasicDlg::GetSeletedIndexOnUserListInMfcBasicDlg()
{
	return m_selectedIndexOnUserList;
}

int CmfcBasicDlg::GetUserIdIntegerInMfcBasicDlg()
{
	return m_userIdInteger;
}

