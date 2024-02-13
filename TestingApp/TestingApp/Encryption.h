#pragma once

class Encryption {
public:
	static string Encrypt(string inputData)
	{
		string outputData = "";
		for (auto sym : inputData)
		{
			sym = sym + 5;
			outputData += sym;
		}
		return outputData;
	}

	static string Dencrypt(string inputData)
	{
		string outputData = "";
		for (auto sym : inputData)
		{
			sym = sym - 5;
			outputData += sym;
		}
		return outputData;
	}
};