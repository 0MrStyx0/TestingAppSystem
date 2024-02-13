#pragma once

class Checker
{
public:
	bool CheckName(string name);
	bool CheckSurname(string surname);
	bool CheckPhoneNumber(string phoneNumber);
	bool CheckLogin(string login, Datastore*& storage);
	bool CheckLogin(string login);
	bool CheckPassword(string password,string repeatedPassword);
	bool CheckData(string login, string password, Datastore*& storage);
	bool CheckAdminData(string login, string password, Datastore*& storage);
	bool AdminChecker(Admin*& admin);
	bool isAdminExists(Datastore*& storage);

	bool CheckSection(string section, Datastore*& storage);
	bool CheckSection(string section, Datastore*& storage, bool Isfound);
	bool CheckSubSection(Subsection*& subsection, Datastore*& storage);
	bool CheckSubSection(string subsection, Datastore*& storage);

	bool CheckQuestion(string correct);
	bool CheckQuestionCount(Datastore*& storage, int count);
};

bool Checker::CheckQuestionCount(Datastore*& storage, int count)
{
	if (count + storage->QuestionSize() > 12)
	{
		cout << "There are 12 questions in total! You have exceeded the limit!!";
		Sleep(1000);
		return false;
	}
}

bool Checker::CheckQuestion(string correct)
{
	if (correct.size() > 1)
	{
		cout << "Only 1 symbol!";
		Sleep(1000);
		return false;
	}
	if (correct[0] < 49 || correct[0] > 52)
	{
		cout << "From 1 to 4 Only!!!";
		Sleep(1000);
		return false;
	}
}

bool Checker::CheckSubSection(Subsection*& subsection, Datastore*& storage)
{
	if (subsection->getName().empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	if (storage->SubsectionSize() == 0)
	{
		return true;
	}
	for (int i = 0; i < storage->SubsectionSize(); i++)
	{
		if (subsection->getName() == storage->getSubsection(i).getName() && subsection->getHisSection() == storage->getSubsection(i).getHisSection())
		{
			cout << "Subsection is already created !" << endl;
			Sleep(1000);
			return false;
		}
	}
}

bool Checker::CheckSubSection(string subsection, Datastore*& storage)
{
	if (subsection.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	if (storage->SubsectionSize() == 0)
	{
		cout << "Subsection not found!" << endl;
		Sleep(1000);
		return false;
	}
	for (int i = 0; i < storage->SubsectionSize(); i++)
	{
		if(i== storage->SubsectionSize()-1&& subsection != storage->getSubsection(i).getName())
		{
			cout << "Subsection not found!" << endl;
			Sleep(1000);
			return false;
		}
		else if (subsection == storage->getSubsection(i).getName())
		{
			return true;
		}
	}
}

bool Checker::CheckSection(string section, Datastore*& storage)
{
	if (section.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	for (int i = 0; i < storage->SectionSize(); i++)
	{
		if (section == storage->getSection(i).getName())
		{
			cout << "Section is already created !" << endl;
			Sleep(1000);
			return false;
		}
	}
}

bool Checker::CheckSection(string section, Datastore*& storage, bool Isfound)
{
	if (section.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	if (storage->SectionSize() == 0)
	{
		cout << "You haven't created any Section !" << endl;
		Sleep(1000);
		return false;
	}
	for (int i = 0; i < storage->SectionSize(); i++)
	{
		if (section != storage->getSection(i).getName() && i == storage->SectionSize() - 1)
		{
			cout << "Section not found !";
			Sleep(1000);
			system("cls");
			return false;
		}
		else if (section == storage->getSection(i).getName())
		{
			Isfound = true;
			return Isfound;
		}
	}
}






bool Checker::CheckName(string name)
{
	if (name.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	for (int i = 0; i < name.size(); i++)
	{
		if (name.size() < 2)
		{
			cout << "2 or more symbols !" << endl;
			Sleep(1000);
			return false;
		}
		else if (name[i] == ' ')
		{
			cout << "No space !" << endl;
			Sleep(1000);
			return false;
		}
		else if (name[i] < 65 || (name[i] > 90 && name[i] < 96) || name[i] > 122)
		{
			cout << "Only letters !" << endl;
			Sleep(1000);
			return false;
		}
		else if (name[0] < 65 || name[0] > 90)
		{
			cout << "First letter must be upper case !" << endl;
			Sleep(1000);
			return false;
		}
		for (int j = i + 1; j < name.size(); j++)
		{
			if (name[j] > 64 && name[j] < 91)
			{
				cout << "Incorrect name !" << endl;
				Sleep(1000);
				return false;
			}
		}
	}
}

bool Checker::CheckSurname(string surname)
{
	if (surname.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	for (int i = 0; i < surname.size(); i++)
	{
		if (surname.size() < 2)
		{
			cout << "2 or more symbols !" << endl;
			Sleep(1000);
			return false;
		}
		else if (surname[i] == ' ')
		{
			cout << "No space !" << endl;
			Sleep(1000);
			return false;
		}
		else if (surname[i] < 65 || (surname[i] > 90 && surname[i] < 96) || surname[i] > 122)
		{
			cout << "Only letters !" << endl;
			Sleep(1000);
			return false;
		}
		else if (surname[0] < 65 || surname[0] > 90)
		{
			cout << "First letter must be upper case !" << endl;
			Sleep(1000);
			return false;
		}
		for (int j = i + 1; j < surname.size(); j++)
		{
			if (surname[j] > 64 && surname[j] < 91)
			{
				cout << "Incorrect surname !" << endl;
				Sleep(1000);
				return false;
			}
		}
	}
}

bool Checker::CheckPhoneNumber(string phoneNumber)
{
	if (phoneNumber.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	for (int i = 0; i < phoneNumber.size(); i++)
	{
		if (phoneNumber[0] != '+')
		{
			cout << "Incorrect number !" << endl;
			Sleep(1000);
			return false;
		}
		else if (phoneNumber.size() - 1 < 8)
		{
			cout << "8 or more digits !" << endl;
			Sleep(1000);
			return false;
		}

		for (int j = i + 1; j < phoneNumber.size(); j++)
		{
			if (phoneNumber[j] < 48 || phoneNumber[j] > 57)
			{
				cout << "Only digits and no space !" << endl;
				Sleep(1000);
				return false;
			}
		}
	}
}

bool Checker::CheckLogin(string login, Datastore*& storage)
{
	if (login.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	if (login == storage->getAdmin().getLogin())
	{
		cout << "Login is already created !" << endl;
		Sleep(1000);
		return false;
	}
	for (int i = 0; i < login.size(); i++)
	{
		if (login.size() < 3)
		{
			cout << "3 or more symbols !" << endl;
			Sleep(1000);
			return false;
		}
		else if (login[i] == ' ')
		{
			cout << "No space !" << endl;
			Sleep(1000);
			return false;
		}
	}

	for (int i = 0; i < storage->Size(); i++)
	{
		if (login == storage->getGuest(i).getLogin())
		{
			cout << "Login is already created !" << endl;
			Sleep(2000);
			return false;
		}
	}
}

bool Checker::CheckLogin(string login)
{
	if (login.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	for (int i = 0; i < login.size(); i++)
	{
		if (login.size() < 3)
		{
			cout << "3 or more symbols !" << endl;
			Sleep(1000);
			return false;
		}
		else if (login[i] == ' ')
		{
			cout << "No space !" << endl;
			Sleep(1000);
			return false;
		}
	}
}

bool Checker::CheckPassword(string password, string repeatedPassword)
{
	if (password.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	int upperCaseCount = 0;
	int digitCount = 0;
	for (int i = 0; i < password.size(); i++)
	{
		if (password[i] > 64 && password[i] < 91)
		{
			upperCaseCount++;
		}
		if (password[i] > 47 && password[i] < 57)
		{
			digitCount++;
		}

		if (password.size() < 6)
		{
			cout << "6 or more symbols !" << endl;
			Sleep(1000);
			return false;
		}
		else if (upperCaseCount < 1 && i == password.size() - 1)
		{
			cout << "At least one character must be capitalized !" << endl;
			Sleep(1000);
			return false;
		}
		else if (digitCount < 1 && i == password.size() - 1)
		{
			cout << "At least one character must be digital !" << endl;
			Sleep(1000);
			return false;
		}
	}

	if (password != repeatedPassword)
	{
		cout << "Password mismatch !" << endl;
		Sleep(1000);
		return false;
	}
	else
	{
		cout << "Success! Accaunt created" << endl;
		Sleep(2000);
		return true;
	}
}

bool Checker::CheckData(string login, string password, Datastore*& storage)
{
	if (login.empty() || password.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}
	if (storage->Size() == 0)
	{
		cout << "You haven't registered any guests !" << endl;
		Sleep(1000);
		return false;
	}
	for (int i = 0; i < storage->Size(); i++)
	{
		if (login != storage->getGuest(i).getLogin() && i == storage->Size() - 1)
		{
			cout << "Invalid login !" << endl;
			Sleep(1000);
			return false;
		}
		else if (password != storage->getGuest(i).getPassword() && i == storage->Size() - 1)
		{
			cout << "Invalid password !" << endl;
			Sleep(1000);
			return false;
		}
		else if (login == storage->getGuest(i).getLogin() && password == storage->getGuest(i).getPassword())
		{
			cout << "Login successful !" << endl;
			Sleep(2000);
			return true;
		}
	}
}
bool Checker::CheckAdminData(string login, string password, Datastore*& storage)
{
	if (login.empty() || password.empty())
	{
		cout << "Empty !" << endl;
		Sleep(1000);
		return false;
	}

	if (login != storage->getAdmin().getLogin())
	{
		cout << "Invalid login !" << endl;
		Sleep(1000);
		return false;
	}
	else if (password != storage->getAdmin().getPassword())
	{
		cout << "Invalid password !" << endl;
		Sleep(1000);
		return false;
	}
	else if (login == storage->getAdmin().getLogin() && password == storage->getAdmin().getPassword())
	{
		cout << "Login successful !" << endl;
		Sleep(2000);
		return true;
	}
}

bool Checker::AdminChecker(Admin*& admin)
{
	if (admin->getAdminCount() > 1)
	{
		system("cls");
		cout << "Only 1 admin !" << endl;
		Sleep(2000);
		system("cls");
		return false;
	}
}

bool Checker::isAdminExists(Datastore*& storage)
{
	if (storage->isAdminExists() == nullptr)
	{
		cout << "Create admin for using programm !" << endl;
		Sleep(1000);
		system("cls");
		return false;
	}
}