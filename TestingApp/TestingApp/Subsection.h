#pragma once

class Subsection
{
	string name;
	string sectionName;

public:
	void setSubsection()
	{
		getline(cin, name);
	}
	void setSubsection(string name)
	{
		this->name = name;
	}

	void setHisSection(string sectionName)
	{
		this->sectionName = sectionName;
	}

	string getName()
	{
		return name;
	}

	string getHisSection()
	{
		return sectionName;
	}

	friend ostream& operator<<(ostream& out, Subsection& subsection)
	{
		out << subsection.name << endl;
		out << subsection.sectionName;
		return out;
	}

	friend istream& operator>>(istream& input, Subsection& subsection)
	{
		string name;
		string sectionName;
		getline(input, name);
		getline(input, sectionName);
		subsection.setHisSection(sectionName);
		subsection.setSubsection(name);
		return input;
	}
};