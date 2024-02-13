#include<string>
#pragma once

using namespace std;

class User
{
	string login;
	string password;
public:

	void setLogin()
	{
		getline(cin, login);
	}

	void setPassword()
	{
		getline(cin, password);
	}

	void LoadLogin(string login)
	{
		this->login = login;
	}

	void LoadPassword(string password)
	{
		this->password = password;
	}

	string getLogin()
	{
		return login;
	}

	string getPassword()
	{
		return password;
	}
};
