
#include "stdafx.h"
#include "User.h"


User::User()
{
	m_userPrimaryNo = 0;
}

User::User(CString name, CString position, CString team, CString phoneNo)
{
	m_insertName = name;
	m_insertPosition = position;
	m_insertTeam = team;
	m_insertPhoneNo = phoneNo;
}

void User::SetUserNo(int no)
{
	m_userPrimaryNo = no;
}
void User::SetUserNmae(CString name) 
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