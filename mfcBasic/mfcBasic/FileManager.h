#pragma once
#include "UserManager.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class FileManager
{
public:
	FileManager();
	virtual~FileManager() = default;

	bool SaveAsCsv(std::shared_ptr<UserManager> m_pUserManager);
	bool LoadAsCsv(std::shared_ptr<UserManager> m_pUserManager);

	std::vector<std::string> ReadRowCsv(std::istream &file, char cDelimiter);

	std::string CStringToString(CString cstr);
	CString StringToCString(std::string str);


private:

};