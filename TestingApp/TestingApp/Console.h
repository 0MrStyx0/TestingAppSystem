#include<conio.h>
#include"DataStore.h"
#include"Save.h"
#include"TestingAppMethods.h"
#pragma once


class Console
{
	Datastore* storage = nullptr;
	Save* file = nullptr;
public:
	Console() :storage{ new Datastore }, file{ new Save }
	{
		file->LoadAdmin(storage);
		file->LoadGuests(storage);
		file->LoadSections(storage);
		file->LoadSubsections(storage);
		file->LoadQuestions(storage);
		file->LoadResults(storage);
	}

	void AdminMenu();
	void GuestMenu();
	
	~Console()
	{
		delete storage;
		delete file;
	}
};


void Console::GuestMenu()
{
	if (storage->isAdminExists() == nullptr)
	{
		cout << "Create admin for using programm !" << endl;
		Sleep(1000);
		system("cls");
		return;
	}
	system("cls");
	while (true)
	{
		cout << "1.Create account\n2.Log In\n3.Exit";
		cout << "\n--> ";
		int selection;
		cin >> selection;
		switch (selection)
		{
		case 1:
			Registration(storage);
			file->SaveGuests(storage);
			break;

		case 2:
			LogIn(storage,file);
			break;

		case 3:
			system("cls");
			return;

		default:
			if (cin.fail() || selection > 3 || selection == 0)
			{
				Error();
			}
		}
	}
}

void Console::AdminMenu()
{
	system("cls");
	while (true)
	{
		cout << "1.Create admin\n2.Log In\n3.Exit";
		cout << "\n--> ";
		int selection;
		cin >> selection;
		switch (selection)
		{
		case 1:
			CreateAdmin(storage);
			if (storage->isAdminExists() == nullptr)
			{
				break;
			}
			else
			{
				file->SaveAdmin(storage);
				break;
			}

		case 2:
			LogInAdmin(storage, file);
			break;

		case 3:
			system("cls");
			return;

		default:
			if (cin.fail() || selection > 3 || selection == 0)
			{
				Error();
			}
		}
	}
}