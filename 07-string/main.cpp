#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string vsWord1 = "", vsWord2 = "";

	ifstream fText("Text.txt");

	if (!fText)
	{
		cout << "Error opening file" << endl;
		return 1;
	}

	for (int i = 0; i < 100; i++)
	{
		string vsOnlyWord1 = "", vsOnlyWord2 = "", 
				vsPunctuation1 = "", vsPunctuation2 = "";

		fText >> vsWord1 >> vsWord2;

		for (string::size_type j = 0; j < vsWord1.size(); j++)
		{
			if (!ispunct(vsWord1[j]) || vsWord1[j] == ' ')
			{
				vsOnlyWord1.push_back(vsWord1[j]);
			}

			if (ispunct(vsWord1[j]))
			{
				vsPunctuation1.push_back(vsWord1[j]);
			}
		}

		for (string::size_type j = 0; j < vsWord2.size(); j++)
		{
			if (!ispunct(vsWord2[j]) || vsWord2[j] == ' ')
			{
				vsOnlyWord2.push_back(vsWord2[j]);
			}

			if (ispunct(vsWord2[j]))
			{
				vsPunctuation2.push_back(vsWord2[j]);
			}
		}

		if ((fText.eof()) && (vsWord2 == ""))
		{
			cout << vsWord1 << endl;
			break;
		}

		cout << vsOnlyWord2 + vsPunctuation1 + " " 
				+ vsOnlyWord1 + vsPunctuation2 + " ";

		vsWord1 = "";
		vsWord2 = "";
	}

	fText.close();

	return 0;
}