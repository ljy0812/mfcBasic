
// mfcBasicDlg.h: 헤더 파일
//

#pragma once
#include "CUserInsertDlg.h"
#include "CShowUserInfo.h"
#include <memory>
#include "UserManager.h"

// CmfcBasicDlg 대화 상자
class CmfcBasicDlg : public CDialogEx
{
// 생성입니다.
public:
	CmfcBasicDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	
	std::shared_ptr<CUserInsertDlg> m_pUserInsertDlg{};
	std::shared_ptr<CShowUserInfo> m_pShowUserInfo{};
	std::shared_ptr<UserManager> m_pUserManager{};

	int selectedIndexOnMenu;
	int selectedIndexOnUserList;

	void ShowUserInfoDlgByUserNo(int userId);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBASIC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_searchButton;
	CEdit m_editSearchById;

	CListBox m_indexList;
	CListCtrl m_viewListCtrl;
		
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	void SettingIndexList();
	void ResettingViewList();

	afx_msg void OnNMDblclkListctrlView(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListctrlView(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLbnDblclkListIndex();
};
