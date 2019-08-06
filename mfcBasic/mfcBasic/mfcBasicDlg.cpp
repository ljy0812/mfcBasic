
// mfcBasicDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "mfcBasic.h"
#include "mfcBasicDlg.h"
#include "afxdialogex.h"
#include "resource.h"
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
	ON_EN_CHANGE(IDC_EDIT_SEARCH_ID, &CmfcBasicDlg::OnEnChangeEditSearchId)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CmfcBasicDlg::OnBnClickedButtonSearch)
	ON_LBN_SELCHANGE(IDC_LIST_INDEX, &CmfcBasicDlg::OnLbnSelchangeListIndex)
	ON_BN_CLICKED(IDOK, &CmfcBasicDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CmfcBasicDlg::OnBnClickedCancel)
	ON_NOTIFY(NM_DBLCLK, IDC_LISTCTRL_VIEW, &CmfcBasicDlg::OnNMDblclkListctrlView)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LISTCTRL_VIEW, &CmfcBasicDlg::OnLvnItemchangedListctrlView)
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



void CmfcBasicDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//ex) 버튼 클릭 시 text변경
	//m_searchButton.SetWindowTextW(TEXT("test"));

	MessageBox(TEXT("example"));
}


void CmfcBasicDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CmfcBasicDlg::OnLbnSelchangeList2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CmfcBasicDlg::OnEnChangeEditSearchId()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CmfcBasicDlg::OnBnClickedButtonSearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//m_editSearchById.SetWindowText(TEXT("ID를 입력해주세요."));

	CString str;
	m_editSearchById.GetWindowTextW(str);
	MessageBox(str);

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
	for (const auto& element : m_pUserManager->m_id2UserMap)
	{		
		m_viewListCtrl.InsertItem(0, element.second->GetUserNoConvertedToString());
		m_viewListCtrl.SetItem(0, 1, LVIF_TEXT, element.second->GetUserName(), 0, 0, 0, 0);
		m_viewListCtrl.SetItem(0, 2, LVIF_TEXT, element.second->GetUserPhoneNo(), 0, 0, 0, 0);
		m_viewListCtrl.SetItem(0, 3, LVIF_TEXT, element.second->GetUserPosition(), 0, 0, 0, 0);
		m_viewListCtrl.SetItem(0, 4, LVIF_TEXT, element.second->GetUserTeam(), 0, 0, 0, 0);

	}
}



void CmfcBasicDlg::OnLbnSelchangeListIndex()
{
	int selectedMenu = m_indexList.GetCurSel();

	switch (selectedMenu)
	{
	case 0:
		m_pUserInsertDlg = std::make_shared<CUserInsertDlg>();

		m_pUserInsertDlg->Create(IDD_DIALOG_INSERT, this);
		m_pUserInsertDlg->ShowWindow(SW_SHOW);

		break;
	case 1:
		MessageBox(TEXT("편집하기"));
		break;
	case 2:
		MessageBox(TEXT("삭제하기"));
		break;
	case 3:
		MessageBox(TEXT("저장하기"));
		break;
	case 4:
		MessageBox(TEXT("불러오기"));
		break;
	default:
		break;
	}
}


void CmfcBasicDlg::OnLbnSelchangeList3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void CmfcBasicDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CmfcBasicDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}




void CmfcBasicDlg::OnNMDblclkListctrlView(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	m_pShowUserInfo = std::make_shared<CShowUserInfo>();
	m_pShowUserInfo->Create(IDD_DIALOG_SHOW_INFO, this);
	m_pShowUserInfo->ShowWindow(SW_SHOW);

	m_pShowUserInfo->m_showNo.SetWindowTextW(TEXT("noChange"));

}


void CmfcBasicDlg::OnLvnItemchangedListctrlView(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
