#include "stdafx.h"
#include "FileManager.h"
#include <iosfwd>



FileManager::FileManager()
{
}

bool FileManager::SaveAsCsv(std::shared_ptr<UserManager> m_pUserManager)
{

	CString strPath = _T("D:\\마이다스주소록_20180214.csv");

	std::ofstream file(strPath);

	if (file.fail())
	{
		file.open(strPath);
	}

	file <<  "#이름" << ',' << "전화번호" << ',' << "직함" << ',' << "부서";
	file << '\n';

	for (const auto& element : m_pUserManager->GetUserMap())
	{
		file << CStringToString(element.second->GetUserNameW()) << ',' <<
			 CStringToString(element.second->GetUserPhoneNumber()) << ',' <<
			 CStringToString(element.second->GetUserPosition()) << ',' <<
			 CStringToString(element.second->GetUserTeam());
		file << '\n';
	}

	if (file.fail())
	{
		return false;
	}

	file.close();

	return true;
}

bool FileManager::LoadAsCsv(std::shared_ptr<UserManager> m_pUserManager)
{
	std::shared_ptr<User> newUser;

	CString strPath = _T("D:\\마이다스주소록_20180214.csv");

	CString userName;
	CString userPhoneNumber;
	CString userPosition;
	CString userTeam;

	std::ifstream file(strPath);

	if (file.fail())
	{
		return false;
	}

	while (file.good())
	{
		std::vector<std::string> row = ReadRowCsv(file, ',');

		if (!row[0].find("#"))
		{
			continue;
		}
		else
		{
			userName = StringToCString(row[0]);
			userTeam = StringToCString(row[1]);
			userPosition = StringToCString(row[2]);
			userPhoneNumber = StringToCString(row[3]);

			newUser = std::make_shared<User>(userName, userPhoneNumber, userPosition, userTeam);
			m_pUserManager->AssignMemoryAndInsertUserInformation(newUser);

		}
	}

	file.close();
	return true;
}


std::vector<std::string> FileManager::ReadRowCsv(std::istream &file, char cDelimiter)
{
	std::stringstream stringStream;
	bool inquotes = false;
	std::vector<std::string> row;

	while (file.good())
	{
		char getCharFromFile = file.get();
		if (!inquotes && getCharFromFile == '"')
		{
			inquotes = true;
		}
		else if (inquotes && getCharFromFile == '"')
		{
			if (file.peek() == '"')
			{
				stringStream << (char)file.get();
			}
			else
			{
				inquotes = false;
			}
		}
		else if (!inquotes && getCharFromFile == cDelimiter)
		{
			row.push_back(stringStream.str());
			stringStream.str("");
		}
		else if (!inquotes && (getCharFromFile == '\r' || getCharFromFile == '\n'))
		{
			if (file.peek() == '\n')
			{
				file.get();
			}
			row.push_back(stringStream.str());
			return row;
		}
		else
		{
			stringStream << getCharFromFile;
		}
	}

	return row;

}

std::string FileManager::CStringToString(CString cstr)
{
	std::string str = "";

	str = CT2CA(cstr);

	return str;
}

CString FileManager::StringToCString(std::string str)
{
	CString cstr = _T("");

	cstr = str.c_str();
	cstr += '\0';

	return cstr;

}
