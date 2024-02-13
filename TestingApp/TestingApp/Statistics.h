#pragma once

class Statistics
{
	string login;
	string sectionName;
	string subsectionName;
	int Correct;
	int inCorrect;

public:

	void setLogin(string login)
	{
		this->login = login;
	}

	void setSectionName(string section)
	{
		sectionName = section;
	}

	void setSubsectionName(string subsection)
	{
		subsectionName = subsection;
	}

	void setCorrect(int Correct)
	{
		this->Correct = Correct;
	}

	void setInCorrect(int inCorrect)
	{
		this->inCorrect = inCorrect;
	}

	string getLogin()
	{
		return login;
	}

	string getSection()
	{
		return sectionName;
	}

	string getSubsection()
	{
		return subsectionName;
	}

	int getCorrect()
	{
		return Correct;
	}

	int getInCorrect()
	{
		return inCorrect;
	}

	float getPercent()
	{
		return (Correct * 100) / (Correct + inCorrect);
	}

	friend ostream& operator<<(ostream& out, Statistics& stat)
	{
		out << stat.Correct << endl;
		out << stat.inCorrect << endl;
		out << stat.sectionName << endl;
		out << stat.subsectionName << endl;
		out << stat.login;
		return out;
	}

	friend istream& operator>>(istream& input, Statistics& stat)
	{
		input >> stat.Correct >> stat.inCorrect;
		input.ignore();
		string SectionName, SubsectionName, login;
		getline(input, SectionName);
		getline(input, SubsectionName);
		getline(input, login);
		stat.setSectionName(SectionName);
		stat.setSubsectionName(SubsectionName);
		stat.setLogin(login);
		return input;
	}
};