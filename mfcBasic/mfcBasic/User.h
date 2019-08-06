#pragma once
#include <afxstr.h>

class User
{
public:
	User();
	User(CString name, CString position, CString team, CString phoneNo);
	~User()
	{
	}
	void SetUserNo(int no);
	void SetUserNmae(CString name);
	void SetUserPosition(CString position);
	void SetUserTeam(CString team);
	void SetUserPhoneNo(CString phoneNo);

	int GetUserNo();
	CString GetUserNoConvertedToString();
	CString GetUserName();
	CString GetUserPosition();
	CString GetUserTeam();
	CString GetUserPhoneNo();

private: 
	int m_userPrimaryNo;
	CString m_insertName;
	CString m_insertPosition;
	CString m_insertTeam;
	CString m_insertPhoneNo;

};