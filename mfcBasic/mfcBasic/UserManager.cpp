
#include "stdafx.h"
#include "UserManager.h"
#include "User.h"

UserManager::UserManager()
{
	autoIncresementForUserId = 0;
}

void UserManager::AssignMemoryAndInsertUserInfomation(std::shared_ptr<User> newUser)
{
	newUser->SetUserNo(++autoIncresementForUserId);
	m_id2UserMap.emplace(autoIncresementForUserId, newUser);
}
//
//std::shared_ptr<User> UserManager::ShowAllOfUserInfomation(int userId)
//{
//}