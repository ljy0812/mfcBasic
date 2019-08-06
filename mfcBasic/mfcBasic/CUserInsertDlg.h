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
	CUserInsertDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUserInsertDlg();

	bool IsWrittenAllOfElementsForInsert(std::shared_ptr<User> newUser);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	CmfcBasicDlg* m_pMainDlg = (CmfcBasicDlg*)AfxGetApp()->m_pMainWnd;

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_insertName;
	CEdit m_insertPosition;
	CEdit m_insertTeam;
	CEdit m_insertPhoneNo;

	CButton m_insertButton;

	afx_msg void OnBnClickedButtonInsert();

	

};
