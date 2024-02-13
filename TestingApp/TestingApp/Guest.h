#include"User.h"
#include"Encryption.h"
#include"Statistics.h"
#pragma once

class Guest :public User
{
	string name;
	string surname;
	string phoneNumber;
public:



	void setName()
	{
		getline(cin, name);
	}

	void setSurname()
	{
		getline(cin, surname);
	}

	void setPhoneNumber()
	{
		getline(cin, phoneNumber);
	}

	string getName()
	{
		return name;
	}

	string getSurname()
	{
		return surname;
	}

	string getPhoneNumber()
	{
		return phoneNumber;
	}

	friend ostream& operator<<(ostream& out, Guest& guest)
	{
		Encryption encrypt;
		out << guest.name << endl;
		out << guest.surname << endl;
		out << guest.phoneNumber << endl;
		out << guest.getLogin() << endl;
		out << encrypt.Encrypt(guest.getPassword());
		return out;
	}

	friend istream& operator>>(istream& input, Guest& guest)
	{
		Encryption dencrypt;
		input >> guest.name;
		input >> guest.surname;
		input >> guest.phoneNumber;
		string login;
		string password;
		input >> login;
		input >> password;
		guest.LoadLogin(login);
		guest.LoadPassword(dencrypt.Dencrypt(password));
		return input;
	}
};