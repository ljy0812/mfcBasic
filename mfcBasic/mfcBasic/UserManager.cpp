
#include "stdafx.h"
#include "UserManager.h"
#include "User.h"

UserManager::UserManager()
{
	autoIncresementForUserId = 0;
}

void UserManager::AssignMemoryAndInsertUserInformation(std::shared_ptr<User> newUser)
{
	newUser->SetUserNo(++autoIncresementForUserId);
	m_id2UserMap.emplace(autoIncresementForUserId, newUser);
}

void UserManager::UpdateUserInformation(int userId, std::shared_ptr<User> newUser)
{
	m_id2UserMap[userId]->SetUserName(newUser->GetUserName());
	m_id2UserMap[userId]->SetUserPhoneNo(newUser->GetUserPhoneNo());
	m_id2UserMap[userId]->SetUserPosition(newUser->GetUserPosition());
	m_id2UserMap[userId]->SetUserTeam(newUser->GetUserTeam());
}

bool UserManager::DeleteUser(int userId)
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

bool UserManager::SearchUserByUserNo(CString userId)
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

