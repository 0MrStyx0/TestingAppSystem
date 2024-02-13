#include"Checker.h"
#pragma once

class ConsoleUser
{

public:
	void GuestMenu(string login, Datastore*& storage, Save*& file);
	void AdminMenu(string login, Datastore*& storage, Save*& file);
};

void Registration(Datastore*& storage)
{
	Checker* checker = new Checker;
	system("cls");
	cin.ignore();

	Guest* guest = new Guest;

	while (true)
	{
		cout << "Name --> ";
		guest->setName();
		if (checker->CheckName(guest->getName()) == false)
		{
			system("cls");
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "Surname --> ";
		guest->setSurname();
		if (checker->CheckSurname(guest->getSurname()) == false)
		{
			system("cls");
			cout << "Name --> " << guest->getName() << endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "Phone Number --> ";
		guest->setPhoneNumber();
		if (checker->CheckPhoneNumber(guest->getPhoneNumber()) == false)
		{
			system("cls");
			cout << "Name --> " << guest->getName() << endl;
			cout << "Surname --> " << guest->getSurname() << endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "Login --> ";
		guest->setLogin();
		if (checker->CheckLogin(guest->getLogin(), storage) == false)
		{
			system("cls");
			cout << "Name --> " << guest->getName() << endl;
			cout << "Surname --> " << guest->getSurname() << endl;
			cout << "Phone Number --> " << guest->getPhoneNumber() << endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "Password --> ";
		guest->setPassword();
		cout << "Repeat Password --> ";
		string repeatedPassword;
		getline(cin, repeatedPassword);
		if (checker->CheckPassword(guest->getPassword(), repeatedPassword) == false)
		{
			system("cls");
			cout << "Name --> " << guest->getName() << endl;
			cout << "Surname --> " << guest->getSurname() << endl;
			cout << "Phone Number --> " << guest->getPhoneNumber() << endl;
			cout << "Login --> " << guest->getLogin() << endl;
		}
		else
		{
			system("cls");
			storage->AddGuest(*guest);
			delete guest;
			delete checker;
			break;
		}
	}
}

void CreateAdmin(Datastore*& storage)
{
	Admin* admin = new Admin;
	Checker* checker = new Checker;
	if (checker->AdminChecker(admin) == false)
	{
		system("cls");
		delete admin;
		delete checker;
		return;
	}
	system("cls");
	cin.ignore();

	while (true)
	{
		cout << "Login --> ";
		admin->setLogin();
		if (checker->CheckLogin(admin->getLogin()) == false)
		{
			system("cls");
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "Password --> ";
		admin->setPassword();
		cout << "Repeat Password --> ";
		string repeatedPassword;
		getline(cin, repeatedPassword);
		if (checker->CheckPassword(admin->getPassword(), repeatedPassword) == false)
		{
			system("cls");
			cout << "Login --> " << admin->getLogin() << endl;
		}
		else
		{
			storage->AddAdmin(admin);
			system("cls");
			admin = nullptr;
			delete checker;
			break;
		}
	}
}

void LogIn(Datastore*& storage, Save*& file)
{
	cin.ignore();
	Checker* checker = new Checker;
	ConsoleUser* consoleUser = new ConsoleUser;
	system("cls");

	string login, password;

	cout << "Login --> ";
	getline(cin, login);

	cout << "Password --> ";
	getline(cin, password);

	if (checker->CheckData(login, password, storage) == false)
	{
		system("cls");
		return;
	}
	else
	{
		delete checker;
		system("cls");
		consoleUser->GuestMenu(login, storage,file);
	}
}

void LogInAdmin(Datastore*& storage, Save*& file)
{
	cin.ignore();
	system("cls");
	Checker* checker = new Checker;
	ConsoleUser* consoleUser = new ConsoleUser;

	if (checker->isAdminExists(storage) == false)
	{
		return;
	}

	string login, password;

	cout << "Login --> ";
	getline(cin, login);

	cout << "Password --> ";
	getline(cin, password);

	if (checker->CheckAdminData(login, password, storage) == false)
	{
		system("cls");
		return;
	}
	else
	{
		delete checker;
		system("cls");
		consoleUser->AdminMenu(login, storage, file);
	}
}

void DeleteUser(Datastore*& storage)
{
	cin.ignore();
	system("cls");

	string login, password;

	cout << "Login --> ";
	getline(cin, login);

	cout << "Password --> ";
	getline(cin, password);

	if (storage->Size() == 0)
	{
		cout << "You haven't registered any guests !" << endl;
		Sleep(1000);
		system("cls");
		return;
	}

	for (int i = 0; i < storage->Size(); i++)
	{
		if (login == storage->getGuest(i).getLogin() && password == storage->getGuest(i).getPassword())
		{
			storage->DeleteGuest().erase(storage->DeleteGuest().begin() + i);
			cout << "Accaunt was deleted !" << endl;
			Sleep(2000);
			system("cls");
			break;
		}
		else if ((login != storage->getGuest(i).getLogin() || password != storage->getGuest(i).getPassword()) && i == storage->Size() - 1)
		{
			cout << "Error !" << endl;
			Sleep(1000);
			system("cls");
			break;
		}
	}
}

void Error()
{
	cout << "Error!";
	Sleep(1000);
	system("cls");
	cin.clear();
	cin.ignore(10000, '\n');
}

void CreateSection(Datastore*& storage)
{
	system("cls");
	cin.ignore();
	Section* section = new Section;
	Checker* checker = new Checker;

	while (true)
	{
		cout << "Section name --> ";
		section->setSection();
		if (checker->CheckSection(section->getName(), storage) == false)
		{
			system("cls");
		}
		else
		{
			storage->AddSection(*section);
			cout << "Section created";
			Sleep(1000);
			system("cls");
			delete section;
			delete checker;
			break;
		}
	}
}

void CreateSubSection(Datastore*& storage)
{
	system("cls");
	cin.ignore();
	Checker* checker = new Checker;

	cout << "Section name --> ";
	bool Isfound = false;
	string section;
	getline(cin, section);
	if (checker->CheckSection(section, storage, Isfound) == false)
	{
		system("cls");
		return;
	}
	else
	{
		Subsection* subsection = new Subsection;
		subsection->setHisSection(section);

		cout << "Subsection name --> ";
		subsection->setSubsection();

		if (checker->CheckSubSection(subsection, storage) == false)
		{
			system("cls");
			return;
		}
		else
		{
			storage->AddSubSection(*subsection);
			cout << "Subsection created";
			Sleep(1000);
			system("cls");
			delete checker;
			delete subsection;
		}
	}
}

void CreateQuestions(Datastore*& storage)
{
	system("cls");
	cin.ignore();
	Checker* checker = new Checker;

	cout << "Section --> ";
	string section;
	getline(cin, section);
	bool Isfound = false;
	if (checker->CheckSection(section, storage, Isfound) == false)
	{
		system("cls");
		return;
	}
	else
	{
		cout << "Subsection --> ";
		string subsection;
		getline(cin, subsection);
		if (checker->CheckSubSection(subsection, storage) == false)
		{
			system("cls");
			return;
		}
		else
		{
			delete checker;
			while (true)
			{
				int questionCount;
				cout << "Question Count --> ";
				cin >> questionCount;
				if (checker->CheckQuestionCount(storage, questionCount) == false)
				{
					system("cls");
					return;
				}
				else if (questionCount == 0 || questionCount < 0)
				{
					cout << "Error!" << endl;
					Sleep(1000);
					system("cls");
					break;
				}
				else
				{
					Checker* checker = new Checker;
					cin.ignore();
					int counter = 0;
					while (counter < questionCount)
					{
						int answerCount = 0;
						Question* question = new Question;
						question->setSectionName(section);
						question->setSubsectionName(subsection);
						cout << "Question " << counter + 1 << ": ";
						question->setQuestion();
						while (answerCount < 4)
						{
							cout << "Answer " << answerCount + 1 << ": ";
							question->setAnswer(answerCount);
							answerCount++;
						}
						cout << "Correct answer: ";
						question->setCorrect();
						if (checker->CheckQuestion(question->getCorrect()) == false)
						{
							system("cls");
							return;
						}
						else
						{
							if (counter == questionCount - 1)
							{
								cout << "Questions are created";
								storage->AddQuestion(*question);
								Sleep(1000);
								system("cls");
								delete question;
								delete checker;
								return;
							}
							else
							{
								storage->AddQuestion(*question);
								delete question;
							}
						}
						cout << endl;
						counter++;
					}
				}
			}
		}
	}
}

void DeleteSection(Datastore*& storage)
{
	cin.ignore();
	system("cls");

	string section;
	cout << "Section --> ";
	getline(cin, section);
	for (int i = 0; i < storage->SectionSize(); i++)
	{
		if (section == storage->getSection(i).getName())
		{
			storage->DeleteSection().erase(storage->DeleteSection().begin() + i);
		}
		else if (section != storage->getSection(i).getName() && i == storage->SectionSize() - 1)
		{
			cout << "Error !" << endl;
			Sleep(1000);
			system("cls");
			return;
		}
	}
	int sizeSub = storage->SubsectionSize();
	for (int i = 0; i < sizeSub; i++)
	{
		for (int j = 0; j < storage->SubsectionSize(); j++)
		{
			if (section == storage->getSubsection(j).getHisSection())
			{
				storage->DeleteSubsection().erase(storage->DeleteSubsection().begin() + j);
				break;
			}
		}
	}
	int sizeQ = storage->QuestionSize();
	for (int i = 0; i < sizeQ; i++)
	{
		for (int j = 0; j < storage->QuestionSize(); j++)
		{
			if (section == storage->getQuestions(j).getSectionName())
			{
				storage->DeleteQuestions().erase(storage->DeleteQuestions().begin() + j);
				break;
			}
		}
	}

	int statSize = storage->StatSize();
	for (int i = 0; i < statSize; i++)
	{
		for (int j = 0; j < storage->StatSize(); j++)
		{
			if (storage->getStatistic(j).getSection() == section)
			{
				storage->DeleteStat().erase(storage->DeleteStat().begin() + j);
				break;
			}
		}
	}
	cout << "Section is deleted";
	Sleep(1000);
	system("cls");
}

void DeleteSubSection(Datastore*& storage)
{
	cin.ignore();
	system("cls");

	string section;
	cout << "Section --> ";
	getline(cin, section);
	for (int i = 0; i < storage->SectionSize(); i++)
	{
		if (section != storage->getSection(i).getName() && i == storage->SectionSize() - 1)
		{
			cout << "Error !" << endl;
			Sleep(1000);
			system("cls");
			return;
		}
		else if(section == storage->getSection(i).getName())
		{
			break;
		}
	}

	string subsection;
	cout << "Subsection --> ";
	getline(cin, subsection);
	for (int i = 0; i < storage->SubsectionSize(); i++)
	{
		if (subsection == storage->getSubsection(i).getName() && section == storage->getSubsection(i).getHisSection())
		{
			storage->DeleteSubsection().erase(storage->DeleteSubsection().begin() + i);
		}
		else if (subsection != storage->getSubsection(i).getName() && i == storage->SubsectionSize() - 1)
		{
			cout << "Error !" << endl;
			Sleep(1000);
			system("cls");
			return;
		}
	}

	int sizeQ = storage->QuestionSize();
	for (int i = 0; i < sizeQ; i++)
	{
		for (int j = 0; j < storage->QuestionSize(); j++)
		{
			if (subsection == storage->getQuestions(j).getSubsectionName())
			{
				storage->DeleteQuestions().erase(storage->DeleteQuestions().begin() + j);
				break;
			}
		}
	}

	int statSize = storage->StatSize();
	for (int i = 0; i < statSize; i++)
	{
		for (int j = 0; j<storage->StatSize(); j++)
		{
			if (storage->getStatistic(j).getSubsection() == subsection && storage->getStatistic(j).getSection() == section)
			{
				storage->DeleteStat().erase(storage->DeleteStat().begin() + j);
				break;
			}
		}
	}
	cout << "Subsection is deleted";
	Sleep(1000);
	system("cls");
}

void TestMenu(Datastore*& storage, Save*& file)
{
	system("cls");
	while (true)
	{
		cout << "1.Create section\n2.Create subsection\n3.Create questions\n4.Test List\n5.Show Questions" << endl;
		cout << "6.Delete Section\n7.Delete Subsection\n8.STATISTICS\n9.Exit";
		cout << "\n--> ";
		int selection;
		cin >> selection;

		switch (selection)
		{
		case 1:
			CreateSection(storage);
			file->SaveSections(storage);
			break;

		case 2:
			CreateSubSection(storage);
			file->SaveSubsections(storage);
			break;

		case 3:
			CreateQuestions(storage);
			file->SaveQuestions(storage);
			break;

		case 4:
			system("cls");
			storage->ShowTestList();
			{char exit = _getch(); }
			system("cls");
			break;

		case 5:
			cin.ignore();
			system("cls");
			{
				cout << "Section --> ";
				string section;
				getline(cin, section);
				cout << "Subsection --> ";
				string subsection;
				getline(cin, subsection);
				storage->ShowQuestions(section, subsection);
			}
			{char exit = _getch(); }
			system("cls");
			break;

		case 6:
			DeleteSection(storage);
			file->SaveSections(storage);
			file->SaveSubsections(storage);
			file->SaveQuestions(storage);
			file->SaveResults(storage);
			break;

		case 7:
			DeleteSubSection(storage);
			file->SaveSubsections(storage);
			file->SaveQuestions(storage);
			file->SaveResults(storage);
			break;

		case 8:
			system("cls");
			storage->ShowStatistics();
			{char exit = _getch(); }
			system("cls");
			break;

		case 9:
			system("cls");
			return;

		default:
			if (cin.fail() || selection > 9 || selection == 0)
			{
				Error();
			}
		}
	}
}

void CheckTesting(string section, string subsection, Datastore*& storage)
{
	for (int i = 0; i < storage->SectionSize(); i++)
	{
		if (section == storage->getSection(i).getName())
		{
			break;
		}
		else if (section != storage->getSection(i).getName() && i == storage->SectionSize() - 1)
		{
			cout << "Error!";
			Sleep(1000);
			system("cls");
			return;
		}
	}
	for (int i = 0; i < storage->SubsectionSize(); i++)
	{
		if (section == storage->getSubsection(i).getHisSection() && subsection == storage->getSubsection(i).getName())
		{
			break;
		}
		else if (section != storage->getSubsection(i).getHisSection() && subsection != storage->getSubsection(i).getName() && i == storage->SubsectionSize() - 1)
		{
			cout << "Error!";
			Sleep(1000);
			system("cls");
			return;
		}
	}
}

void ShowQuestions(string section, string subsection, Datastore*& storage, int& correctCount, int& inCorrectCount)
{
	for (int i = 0; i < storage->QuestionSize(); i++)
	{
		int answerCount = 0;
		if (section == storage->getQuestions(i).getSectionName() && subsection == storage->getQuestions(i).getSubsectionName())
		{
			string choice;
			cout << "Question " << i + 1 << ": " << storage->getQuestions(i).getQuestion() << endl;
			while (answerCount < 4)
			{
				cout << "Answer " << answerCount + 1 << ": " << storage->getQuestions(i).getAnswer(answerCount) << endl;
				answerCount++;
			}
			cout << " --> ";
			getline(cin, choice);
			if (choice == storage->getQuestions(i).getCorrect())
			{
				cout << "CORRECT!" << endl << endl;
				correctCount++;
			}
			else
			{
				cout << "MISTAKE!" << endl << endl;
				inCorrectCount++;
			}
		}
	}
}

void TestGuest(string login, Datastore*& storage)
{
	system("cls");
	cin.ignore();

	cout << "Section --> ";
	string section;
	getline(cin, section);

	cout << "Subsection --> ";
	string subsection;
	getline(cin, subsection);

	CheckTesting(section, subsection, storage);

	int correctCount = 0;
	int inCorrectCount = 0;
	ShowQuestions(section, subsection, storage, correctCount, inCorrectCount);

	Statistics* stat = new Statistics;
	stat->setLogin(login);
	stat->setSectionName(section);
	stat->setSubsectionName(subsection);
	stat->setCorrect(correctCount);
	stat->setInCorrect(inCorrectCount);

	storage->addStatistic(*stat);
	delete stat;
}

void ConsoleUser::GuestMenu(string login, Datastore*& storage,Save*& file)
{
	system("cls");
	while (true)
	{
		cout << "1.Show profile\n2.Take test\n3.Test List\n4.Exit";
		cout << "\n--> ";
		int selection;
		cin >> selection;
		switch (selection)
		{
		case 1:
			system("cls");
			storage->ShowProfile(login);
			{char exit = _getch(); }
			system("cls");
			break;

		case 2:
			TestGuest(login,storage);
			file->SaveResults(storage);
			break;

		case 3:
			system("cls");
			storage->ShowTestList();
			{char exit = _getch(); }
			system("cls");
			break;

		case 4:
			system("cls");
			return;

		default:
			if (cin.fail() || selection > 4 || selection == 0)
			{
				Error();
			}
		}
	}
}

void ConsoleUser::AdminMenu(string login, Datastore*& storage, Save*& file)
{
	system("cls");
	while (true)
	{
		cout << "1.Show Profile\n2.Create a guest\n3.Show Users\n4.Delete user\n5.Test menu\n6.Exit";
		cout << "\n--> ";
		int selection;
		cin >> selection;
		switch (selection)
		{
		case 1:
			system("cls");
			storage->ShowAdmin();
			{char exit = _getch(); }
			system("cls");
			break;

		case 2:
			Registration(storage);
			file->SaveGuests(storage);
			break;

		case 3:
			system("cls");
			storage->ShowGuests();
			{char exit = _getch(); }
			system("cls");
			break;

		case 4:
			DeleteUser(storage);
			file->SaveGuests(storage);
			break;

		case 5:
			TestMenu(storage, file);
			break;

		case 6:
			system("cls");
			return;

		default:
			if (cin.fail() || selection > 6 || selection == 0)
			{
				Error();
			}
		}
	}
}
