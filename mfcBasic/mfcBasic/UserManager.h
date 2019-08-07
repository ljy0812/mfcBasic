#pragma once
#include <map>
#include <memory>
#include "User.h"


class UserManager
{
public:
	UserManager();
	~UserManager()
	{

	}

	int autoIncresementForUserId;
	std::map<int, std::shared_ptr<User>> m_id2UserMap;

	void AssignMemoryAndInsertUserInformation(std::shared_ptr<User> newUser);
	void UpdateUserInformation(int userId, std::shared_ptr<User> newUser);
	bool DeleteUser(int userId);

	//std::shared_ptr<User> ShowAllOfUserInfomation(int userId);

private:

};