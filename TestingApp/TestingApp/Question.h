#pragma once

class Question
{
	string SectionName;
	string SubsectionName;
	string question;
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	string correct;
public:
	void setSectionName(string SectionName)
	{
		this->SectionName = SectionName;
	}

	void setSubsectionName(string SubsectionName)
	{
		this->SubsectionName = SubsectionName;
	}

	void setQuestion()
	{
		getline(cin, question);
	}
	void setQuestion(string question)
	{
		this->question = question;
	}

	void setAnswer(int count)
	{
		if (count == 0)
		{
			getline(cin, answer1);
		}
		else if (count == 1)
		{
			getline(cin, answer2);
		}
		else if (count == 2)
		{
			getline(cin, answer3);
		}
		else if (count == 3)
		{
			getline(cin, answer4);
		}
	}

	void setAnswer1(string answer1)
	{
		this->answer1 = answer1;
	}
	void setAnswer2(string answer2)
	{
		this->answer2 = answer2;
	}
	void setAnswer3(string answer3)
	{
		this->answer3 = answer3;
	}
	void setAnswer4(string answer4)
	{
		this->answer4 = answer4;
	}

	void setCorrect()
	{
		cin >> correct;
		cin.ignore();
	}

	string getAnswer(int count)
	{
		if (count == 0)
		{
			return answer1;
		}
		else if (count == 1)
		{
			return answer2;
		}
		else if (count == 2)
		{
			return answer3;
		}
		else if (count == 3)
		{
			return answer4;
		}
	}

	string getSubsectionName()
	{
		return SubsectionName;
	}

	string getSectionName()
	{
		return SectionName;
	}

	string getQuestion()
	{
		return question;
	}

	string getCorrect()
	{
		return correct;
	}

	friend ostream& operator<<(ostream& out, Question& question)
	{
		out << question.SectionName << endl;
		out << question.SubsectionName << endl;
		out << question.question << endl;
		out << question.answer1 << endl;
		out << question.answer2 << endl;
		out << question.answer3 << endl;
		out << question.answer4 << endl;
		out << question.correct;
		return out;
	}

	friend istream& operator>>(istream& input, Question& question)
	{
		string SectionName, SubsectionName, Question, answer1, answer2, answer3, answer4;
		getline(input, SectionName);
		getline(input, SubsectionName);
		getline(input, Question);
		getline(input, answer1);
		getline(input, answer2);
		getline(input, answer3);
		getline(input, answer4);
		question.setSectionName(SectionName);
		question.setSubsectionName(SubsectionName);
		question.setQuestion(Question);
		question.setAnswer1(answer1);
		question.setAnswer2(answer2);
		question.setAnswer3(answer3);
		question.setAnswer4(answer4);
		input >> question.correct;
		return input;
	}
};