
// mfcBasicDlg.h: 헤더 파일

#pragma once
#include "CUserInsertDlg.h"
#include "CShowUserInfo.h"
#include <memory>
#include "UserManager.h"
#include "resource.h"
#include "FileManager.h"

// CmfcBasicDlg 대화 상자
class CmfcBasicDlg : public CDialogEx
{
// 생성입니다.
public:
	CmfcBasicDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	
	void SettingIndexList();
	void ResettingViewList();

	void ShowUserInfoDlgByUserId(const int& userId);
	void MenuAddUser();
	void MenuEditUserInfo(const int& userId);
	void MenuDeleteUser(const int& userId);
	void MenuFileSave();
	void MenuFileLoad();

	
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	afx_msg void OnNMDblclkListctrlView(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListctrlView(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLbnDblclkListIndex();

	CButton m_searchButton;
	CEdit m_editSearchById;

	CListBox m_indexList;
	CListCtrl m_viewListCtrl;

	std::shared_ptr<UserManager> GetPointerUserManager();

	int GetSeletedIndexOnMenuInMfcBasicDlg();
	int GetSeletedIndexOnUserListInMfcBasicDlg();
	int GetUserIdIntegerInMfcBasicDlg();

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


private:
	std::shared_ptr<CUserInsertDlg> m_pUserInsertDlg{};
	std::shared_ptr<CShowUserInfo> m_pShowUserInfo{};
	std::shared_ptr<UserManager> m_pUserManager{};
	std::shared_ptr<FileManager> m_pFileManager{};

	int m_selectedIndexOnMenu;
	int m_selectedIndexOnUserList;
	int m_userIdInteger;
	
	
};
