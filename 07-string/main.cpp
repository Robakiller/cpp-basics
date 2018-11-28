#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ifstream file_text("Text.txt");

	if (!file_text)
	{
		cout << "Error opening file" << endl;
		return 1;
	}

	string one_line;
	
	while (getline(file_text, one_line))
	{
		istringstream line(one_line);

		for (int i = 0; i < 100; i++)
		{
			string word1 = "", word2 = "",
				only_word1 = "", only_word2 = "",
				punctuation1 = "", punctuation2 = "";

			line >> word1 >> word2;

			for (string::size_type j = 0; j < word1.size(); j++)
			{
				if (!ispunct(word1[j]) || word1[j] == ' ')
				{
					only_word1.push_back(word1[j]);
				}

				if (ispunct(word1[j]))
				{
					punctuation1.push_back(word1[j]);
				}
			}

			for (string::size_type j = 0; j < word2.size(); j++)
			{
				if (!ispunct(word2[j]) || word2[j] == ' ')
				{
					only_word2.push_back(word2[j]);
				}

				if (ispunct(word2[j]))
				{
					punctuation2.push_back(word2[j]);
				}
			}

			if ((line.eof()) && (word2 == ""))
			{
				cout << word1 << endl;
				break;
			}

			cout << only_word2 + punctuation1 + " "
					+ only_word1 + punctuation2 + " ";
		}
	}

	file_text.close();

	return 0;
}