#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    string sentence;

    while (true) {
        getline(cin, sentence);
        if (sentence == "*") {
            break;
        }
        vector<string> words;
        string word = "";
        for (char c : sentence) {
            if (c != ' ') {
                word += c;
            } else {
                words.push_back(word);
                word = "";
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        char firstLetter = tolower(words[0][0]);
        bool tautogram = true;
        for (int i = 1; i < words.size(); i++) {
            if (tolower(words[i][0]) != firstLetter) {
                tautogram = false;
                break;
            }
        }
        if (tautogram) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}
