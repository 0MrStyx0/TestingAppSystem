#pragma once

class Section
{
	string name;
public:

	void setSection()
	{
		getline(cin, name);
	}
	void setSection(string section)
	{
		name = section;
	}

	string getName()
	{
		return name;
	}

	friend ostream& operator<<(ostream& out, Section& section)
	{
		out << section.name;
		return out;
	}

	friend istream& operator>>(istream& input, Section& section)
	{
		string Inputsection;
		getline(input, Inputsection);
		section.setSection(Inputsection);
		return input;
	}
};