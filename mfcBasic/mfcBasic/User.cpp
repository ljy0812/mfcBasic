
#include "stdafx.h"
#include "User.h"


User::User()
{
	m_userPrimaryNo = 0;
}

User::User(CString name, CString phoneNo, CString position, CString team)
{
	m_insertName = name;
	m_insertPhoneNo = phoneNo;
	m_insertPosition = position;
	m_insertTeam = team;
}

void User::SetUserNo(int no)
{
	m_userPrimaryNo = no;
}
void User::SetUserName(CString name) 
{
	m_insertName = name;
}
void User::SetUserPosition(CString position)
{
	m_insertPosition = position;
}
void User::SetUserTeam(CString team)
{
	m_insertTeam = team;
}
void User::SetUserPhoneNo(CString phoneNo)
{
	m_insertPhoneNo = phoneNo;
}
int User::GetUserNo()
{
	return m_userPrimaryNo;
}
CString User::GetUserNoConvertedToString()
{
	CString str;
	str.Format(_T("%d"), m_userPrimaryNo);
	return str;
}
CString User::GetUserName()
{
	return m_insertName;
}
CString User::GetUserPosition()
{
	return m_insertPosition;
}
CString User::GetUserTeam()
{
	return m_insertTeam;
}
CString User::GetUserPhoneNo()
{
	return m_insertPhoneNo;
}