#pragma once


// CShowUserInfo 대화 상자

class CShowUserInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CShowUserInfo)

public:
	CShowUserInfo(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CShowUserInfo();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHOW_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_showNo;
	CStatic m_showName;
	CStatic m_showPhoneNo;
	CStatic m_showPosition;
	CStatic m_showTeam;
};
