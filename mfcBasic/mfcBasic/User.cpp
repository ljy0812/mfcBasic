
#include "stdafx.h"
#include "User.h"


User::User()
{
	m_userPrimaryId = 0;
}

User::User(CString userName, CString phoneNumber, CString position, CString team)
	: m_insertUserName(userName), m_insertUserPhoneNumber(phoneNumber),
	m_insertUserPosition(position),	m_insertUserTeam(team)
{	
}

void User::SetUserId(const int& userId)
{
	m_userPrimaryId = userId;
}
void User::SetUserName(const CString& userName)
{
	m_insertUserName = userName;
}
void User::SetUserPosition(const CString& userPosition)
{
	m_insertUserPosition = userPosition;
}
void User::SetUserTeam(const CString& userTeam)
{
	m_insertUserTeam = userTeam;
}
void User::SetUserphoneNumber(const CString& userPhoneNumber)
{
	m_insertUserPhoneNumber = userPhoneNumber;
}
int User::GetUserNumber()
{
	return m_userPrimaryId;
}
CString User::GetUserIdConvertedToString()
{
	CString str;
	str.Format(_T("%d"), m_userPrimaryId);
	return str;
}
CString User::GetUserName()
{
	return m_insertUserName;
}
CString User::GetUserPosition()
{
	return m_insertUserPosition;
}
CString User::GetUserTeam()
{
	return m_insertUserTeam;
}
CString User::GetUserPhoneNumber()
{
	return m_insertUserPhoneNumber;
}