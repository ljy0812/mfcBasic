#pragma once
#include <memory>
#include "User.h"
#include <unordered_map>


class UserManager
{
public:
	UserManager();
	virtual ~UserManager() = default;
	
	void AssignMemoryAndInsertUserInformation(std::shared_ptr<User> newUser);
	bool UpdateUserInformation(const int& userId, std::shared_ptr<User> newUser);
	bool DeleteUser(const int& userId);
	bool SearchUserByUserId(const CString& userId);

	std::unordered_map<int, std::shared_ptr<User>> GetUserMap() const;
	   
private:
	int m_autoIncresementForUserId;
	std::unordered_map<int, std::shared_ptr<User>> m_id2UserMap;


};