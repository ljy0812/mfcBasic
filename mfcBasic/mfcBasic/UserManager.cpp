
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

//
//std::shared_ptr<User> UserManager::ShowAllOfUserInfomation(int userId)
//{
//}