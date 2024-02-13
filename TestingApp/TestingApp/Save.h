#include<fstream>
#pragma once

class Save
{
public:
	void SaveGuests(Datastore*& storage);
	void SaveAdmin(Datastore*& storage);

	void LoadGuests(Datastore*& storage);
	void LoadAdmin(Datastore*& storage);

	void SaveSections(Datastore*& storage);
	void LoadSections(Datastore*& storage);

	void SaveSubsections(Datastore*& storage);
	void LoadSubsections(Datastore*& storage);

	void SaveQuestions(Datastore*& storage);
	void LoadQuestions(Datastore*& storage);

	void SaveResults(Datastore*& storage);
	void LoadResults(Datastore*& storage);
};

void Save::LoadResults(Datastore*& storage)
{
	ifstream fin("Statistics.txt");

	if (fin.peek() != std::ifstream::traits_type::eof())
	{
		while (!fin.eof())
		{
			Statistics stat;
			fin >> stat;
			storage->addStatistic(stat);
		}
	}
}

void Save::SaveResults(Datastore*& storage)
{
	ofstream fout("Statistics.txt", ios::out);

	for (int i = 0; i < storage->StatSize(); i++)
	{
		if (i < storage->StatSize() - 1)
		{
			fout << storage->getStatistic(i) << endl;
		}
		else
		{
			fout << storage->getStatistic(i);
		}
	}
}

void Save::SaveQuestions(Datastore*& storage)
{
	ofstream fout("Questions.txt", ios::out);

	for (int i = 0; i < storage->QuestionSize(); i++)
	{
		if (i < storage->QuestionSize() - 1)
		{
			fout << storage->getQuestions(i) << endl;
		}
		else
		{
			fout << storage->getQuestions(i);
		}
	}
}

void Save::LoadQuestions(Datastore*& storage)
{
	ifstream fin("Questions.txt");

	if (fin.peek() != std::ifstream::traits_type::eof())
	{
		while (!fin.eof())
		{
			Question question;
			fin >> question;
			storage->AddQuestion(question);
		}
	}
}


void Save::LoadSubsections(Datastore*& storage)
{
	ifstream fin("Subsections.txt");

	if (fin.peek() != std::ifstream::traits_type::eof())
	{
		while (!fin.eof())
		{
			Subsection subsection;
			fin >> subsection;
			storage->AddSubSection(subsection);
		}
	}
}

void Save::SaveSubsections(Datastore*& storage)
{
	ofstream fout("Subsections.txt", ios::out);

	for (int i = 0; i < storage->SubsectionSize(); i++)
	{
		if (i < storage->SubsectionSize() - 1)
		{
			fout << storage->getSubsection(i) << endl;
		}
		else
		{
			fout << storage->getSubsection(i);
		}
	}
}

void Save::LoadSections(Datastore*& storage)
{
	ifstream fin("Sections.txt");

	if (fin.peek() != std::ifstream::traits_type::eof())
	{
		while (!fin.eof())
		{
			Section section;
			fin >> section;
			storage->AddSection(section);
		}
	}
}

void Save::SaveSections(Datastore*& storage)
{
	ofstream fout("Sections.txt", ios::out);

	for (int i = 0; i < storage->SectionSize(); i++)
	{
		if (i < storage->SectionSize() - 1)
		{
			fout << storage->getSection(i) << endl;
		}
		else
		{
			fout << storage->getSection(i);
		}
	}
}

void Save::SaveGuests(Datastore*& storage)
{
	ofstream fout("Guests.txt", ios::out);

	for (int i = 0; i < storage->Size(); i++)
	{
		if (i < storage->Size() - 1)
		{
			fout << storage->getGuest(i) << endl;
		}
		else
		{
			fout << storage->getGuest(i);
		}
	}
}

void Save::LoadGuests(Datastore*& storage)
{
	ifstream fin("Guests.txt");

	if (fin.peek() != std::ifstream::traits_type::eof())
	{
		while (!fin.eof())
		{
			Guest guest;
			fin >> guest;
			storage->AddGuest(guest);
		}
	}
}

void Save::SaveAdmin(Datastore*& storage)
{
	ofstream fout("Admin.txt");
	fout << storage->getAdmin();
}

void Save::LoadAdmin(Datastore*& storage)
{
	ifstream fin("Admin.txt");
	if (fin.peek() != std::ifstream::traits_type::eof())
	{
		while (!fin.eof())
		{
			Admin* admin = new Admin;
			fin >> admin;
			storage->AddAdmin(admin);
		}
	}
}