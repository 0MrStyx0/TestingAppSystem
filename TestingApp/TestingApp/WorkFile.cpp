#include<iostream>
#include<Windows.h>
#include"Console.h"

using namespace std;

int main()
{
	Console console;
	while (true)
	{
		cout << "1.Admin\n2.Guest\n3.Exit";
		cout << "\n--> ";
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			console.AdminMenu();
		}
		else if (choice == 2)
		{
			console.GuestMenu();
		}
		else if (choice == 3)
		{
			system("cls");
			break;
		}
		else if (cin.fail() || choice > 3 || choice == 0)
		{
			Error();
		}
	}
}