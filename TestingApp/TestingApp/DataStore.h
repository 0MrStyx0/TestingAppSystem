#include<vector>
#include"Admin.h"
#include"Guest.h"
#include"Section.h"
#include"Subsection.h"
#include"Question.h"


#pragma once

class Datastore
{
	Admin* admin = nullptr;
	vector<Guest> storage;
	vector<Section> sections;
	vector<Subsection> subsections;
	vector<Question> questions;
	vector<Statistics> statistic;
	

public:



	void ShowStatistics()
	{
		for (auto section : sections)
		{
			cout << "-------------" << endl;
			cout << "SECTION: ";
			cout << section.getName() << endl;
			cout << "-------------" << endl;
			
			for (auto subsection : subsections)
			{
				if (subsection.getHisSection() == section.getName())
				{
					cout << "SUBSECTION: ";
					cout << subsection.getName() << endl;
					for (auto guest : storage)
					{
						cout << guest.getLogin() << endl;
						cout << "Attempts: " << endl;
						for (auto stat : statistic)
						{
							if (guest.getLogin() == stat.getLogin() && subsection.getHisSection() == stat.getSection()
								&& subsection.getName() == stat.getSubsection())
							{
								cout << " --- " << stat.getPercent() << "%" << endl;
							}
						}
						cout << endl;
					}
				}
				cout << endl;
			}
			cout << endl;
		}
	}

	////////////////////////////////

	int StatSize()
	{
		return statistic.size();
	}

	void addStatistic(Statistics& stat)
	{
		statistic.push_back(stat);
	}

	Statistics& getStatistic(int index)
	{
		return statistic.at(index);
	}

	vector<Statistics>& DeleteStat()
	{
		return statistic;
	}


	void ShowQuestions(string section, string subsection)
	{
		int counter = 0;
		for (auto question : questions)
		{
			int answerCount = 0;
			for (auto subsectionEl : subsections)
			{
				if (subsectionEl.getName() == question.getSubsectionName() && subsection == question.getSubsectionName()
				   && section == question.getSectionName() && subsectionEl.getHisSection() == question.getSectionName())
				{
					cout << "Question " << counter + 1 << ": " << question.getQuestion() << endl;
					while (answerCount < 4)
					{
						cout << answerCount + 1 << ". " << question.getAnswer(answerCount) << endl;
						answerCount++;
					}
					cout << "Correct: " << question.getCorrect() << endl << endl;
				}
			}
			counter++;
		}
	}

	void ShowTestList()
	{
		
		for (auto section : sections)
		{
			cout << "SECTION: " << endl;
			cout << section.getName() << endl;
			cout << "SUBSECTIONS: " << endl;
			for (auto subsection : subsections)
			{
				if (subsection.getHisSection() == section.getName())
				{
					cout << subsection.getName() << endl;
				}
			}
			cout << endl;
		}
	}

	/////////////Связано с Вопросами////////////////////

	vector<Question>& DeleteQuestions()
	{
		return questions;
	}

	void AddQuestion(Question& question)
	{
		questions.push_back(question);
	}

	int QuestionSize()
	{
		return questions.size();
	}

	Question& getQuestions(int index)
	{
		return questions.at(index);
	}

	/////////////Связано с Субсекцией////////////////////
	vector<Subsection>& DeleteSubsection()
	{
		return subsections;
	}

	void AddSubSection(Subsection& subsection)
	{
		subsections.push_back(subsection);
	}

	Subsection& getSubsection(int index)
	{
		return subsections.at(index);
	}

	int SubsectionSize()
	{
		return subsections.size();
	}
	
	/////////////Связано с Секцией////////////////////

	vector<Section>& DeleteSection()
	{
		return sections;
	}

	void AddSection(Section& section)
	{
		sections.push_back(section);
	}

	Section& getSection(int index)
	{
		return sections.at(index);
	}

	int SectionSize()
	{
		return sections.size();
	}

	/////////////Связано с Пользователями////////////////////
	void AddGuest(Guest& guest)
	{
		storage.push_back(guest);
	}

	void AddAdmin(Admin* admin)
	{
		this->admin = admin;
	}

	void ShowGuests()
	{
		for (auto guest : storage)
		{
			cout << "Name: " << guest.getName() << endl;
			cout << "Surname: " << guest.getSurname() << endl;
			cout << "Login: " << guest.getLogin() << endl;
			cout << "Password: " << guest.getPassword() << endl;
			cout << "Phone Number: " << guest.getPhoneNumber() << endl << endl;
		}
	}

	void ShowProfile(string login)
	{
		for (auto guest : storage)
		{
			if (login == guest.getLogin())
			{
				cout << "Name: " << guest.getName() << endl;
				cout << "Surname: " << guest.getSurname() << endl;
				cout << "Login: " << guest.getLogin() << endl;
				cout << "Phone Number: " << guest.getPhoneNumber() << endl << endl;
			}
		}
	}

	void ShowAdmin()
	{
		cout << "Login: " << admin->getLogin() << endl;
		cout << "Password: " << admin->getPassword() << endl;
	}

	int Size()
	{
		return storage.size();
	}

	vector<Guest>& DeleteGuest()
	{
		return storage;
	}

	Guest& getGuest(int index)
	{
		return storage.at(index);
	}

	Admin* isAdminExists()
	{
		return admin;
	}

	Admin& getAdmin()
	{
		return *admin;
	}
};