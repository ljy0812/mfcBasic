#pragma once
#include <memory.h>
#include <iostream>
#include <string>
#include "User.h"

class CmfcBasicDlg;

// CUserInsertDlg 대화 상자
class CUserInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUserInsertDlg)

public:
	CUserInsertDlg(CmfcBasicDlg* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUserInsertDlg() = default;

	bool IsWrittenAllOfElementsForInsert(std::shared_ptr<User> newUser);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CEdit m_insertName;
	CEdit m_insertPosition;
	CEdit m_insertTeam;
	CEdit m_insertPhoneNo;
	CButton m_insertButton;

	afx_msg void OnBnClickedButtonInsert();
	afx_msg void OnBnKillfocusButtonInsert();
	afx_msg void OnBnSetfocusButtonInsert();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	CmfcBasicDlg* m_pMainDlg;

	DECLARE_MESSAGE_MAP()
	
private:
	bool m_isFocusingNow;
	
};
