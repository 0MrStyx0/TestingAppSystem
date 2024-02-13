#include"User.h"
#include"Encryption.h"
#pragma once

class Admin :public User
{
	static int count;
public:
	Admin()
	{
		count++;
	}

	int getAdminCount()
	{
		return count;
	}

	friend ostream& operator<<(ostream& out, Admin& admin)
	{
		Encryption encrypt;
		out << admin.getLogin() << endl;
		out << encrypt.Encrypt(admin.getPassword());
		return out;
	}

	friend istream& operator>>(istream& input, Admin* admin)
	{
		Encryption dencrypt;
		string login;
		string password;
		input >> login;
		input >> password;
		admin->LoadLogin(login);
		admin->LoadPassword(dencrypt.Dencrypt(password));
		return input;
	}

	~Admin()
	{
		count--;
	}
};

int Admin::count = 0;