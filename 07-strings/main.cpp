#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string* SeparateWordAndPuncts(string);

int main() {
    ifstream file_text("Text.txt");

    if (!file_text) {
        cout << "Error opening file: Text.txt\n";
        return 1;
    }

    string line;
    while (getline(file_text, line)) {
        istringstream line_stream(line);
        while (true) {
            string word1, word2;
            line_stream >> word1 >> word2;

            if (word1 == "") {
                break;
            }
            else if (word2 == "") {
                cout << word1;
            }
            else {
                string* word_and_puncts1 = SeparateWordAndPuncts(word1);
                string* word_and_puncts2 = SeparateWordAndPuncts(word2);

                cout << word_and_puncts1[0] << word_and_puncts2[1];
                cout << word_and_puncts1[2] << " ";
                cout << word_and_puncts2[0] << word_and_puncts1[1];
                cout << word_and_puncts2[2] << " ";

                delete[] word_and_puncts1;
                delete[] word_and_puncts2;
            }
        }
        cout << endl;
    }

    file_text.close();

    return 0;
}

string* SeparateWordAndPuncts(string word) {
    size_t word_len = word.length();

    // Before the word.
    int i = 0;
    while (ispunct(word[i])) i++;
    word_len -= i;

    string puncts_before_word = word.substr(0, i);
    string only_word = word.substr(i, word_len);

    // After the word.
    i = 0;
    while (ispunct(only_word[word_len - i - 1])) i++;
    word_len -= i;

    string puncts_after_word = only_word.substr(word_len, i);
    only_word = only_word.substr(0, word_len);

    return new string[3]{ puncts_before_word, only_word, puncts_after_word };
}