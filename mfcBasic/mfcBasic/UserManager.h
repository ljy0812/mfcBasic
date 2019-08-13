#pragma once
#include <map>
#include <memory>
#include "User.h"


class UserManager
{
public:
	UserManager();
	virtual ~UserManager() = default;
	
	void AssignMemoryAndInsertUserInformation(std::shared_ptr<User> newUser);
	bool UpdateUserInformation(const int& userId, std::shared_ptr<User> newUser);
	bool DeleteUser(const int& userId);
	bool SearchUserByUserId(const CString& userId);

	std::map<int, std::shared_ptr<User>> GetUserMap();
	   
private:
	int m_autoIncresementForUserId;
	std::map<int, std::shared_ptr<User>> m_id2UserMap;


};