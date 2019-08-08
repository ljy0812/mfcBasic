
#include "stdafx.h"
#include "UserManager.h"
#include "User.h"

UserManager::UserManager()
{
	m_autoIncresementForUserId = 0;
}

void UserManager::AssignMemoryAndInsertUserInformation(std::shared_ptr<User> newUser)
{
	newUser->SetUserId(++m_autoIncresementForUserId);
	m_id2UserMap.emplace(m_autoIncresementForUserId, newUser);
}

void UserManager::UpdateUserInformation(const int& userId, std::shared_ptr<User> newUser)
{
	const auto& userName = newUser->GetUserName();
	const auto& userPhoneNumber = newUser->GetUserPhoneNumber();
	const auto& userPosition = newUser->GetUserPosition();
	const auto& userTeam = newUser->GetUserTeam();

	m_id2UserMap[userId]->SetUserName(userName);
	m_id2UserMap[userId]->SetUserphoneNumber(userPhoneNumber);
	m_id2UserMap[userId]->SetUserPosition(userPosition);
	m_id2UserMap[userId]->SetUserTeam(userTeam);
}

bool UserManager::DeleteUser(const int& userId)
{
	if (m_id2UserMap.find(userId) != m_id2UserMap.end())
	{
		m_id2UserMap.erase(userId);
		return true;
	}
	else
	{
		return false;
	}
		
}

bool UserManager::SearchUserByUserId(const CString& userId)
{
	if (userId.IsEmpty() || (userId.Find(_T(" ")) >= 0))
	{
		return false;
	}
	else
	{
		if (m_id2UserMap.find(_ttoi(userId)) != m_id2UserMap.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

std::map<int, std::shared_ptr<User>> UserManager::GetUserMap()
{
	return m_id2UserMap;
}

