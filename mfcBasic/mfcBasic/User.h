#pragma once
#include <afxstr.h>

class User
{
public:
	User();
	User(CString userName, CString userPhoneNumber, CString userPosition, CString userTeam);
	virtual ~User() = default;

	void SetUserId(const int& userId);
	void SetUserName(const CString& userName);
	void SetUserPosition(const CString& userPosition);
	void SetUserTeam(const CString& userTeam);
	void SetUserphoneNumber(const CString& userPhoneNumber);

	int GetUserNumber();
	CString GetUserIdConvertedToString();
	CString GetUserName();
	CString GetUserPosition();
	CString GetUserTeam();
	CString GetUserPhoneNumber();

private: 
	int m_userPrimaryId;
	CString m_insertUserName;
	CString m_insertUserPosition;
	CString m_insertUserTeam;
	CString m_insertUserPhoneNumber;

};