#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <cctype>

using namespace std;

bool isPunctuation(char c) {
    return c == ',' || c == '.' || c == '?' || c == '!' || c == '-' || c == ';';
}

string removePunctuation(const string& word, char& punctuation) {
    punctuation = '\0';
    for (char c : word) {
        if (isPunctuation(c)) {
            punctuation = c;
            return word.substr(0, word.length() - 1);
        }
    }
    return word;
}

int main() {
    string line;
    vector<string> inputWords;

    while (getline(cin, line)) {
        if (line == "end") break;

        stringstream ss(line);
        string word;
        while (ss >> word) {
            inputWords.push_back(word);
        }
    }

    vector<int> wordLengths;
    vector<char> punctuations;
    for (const string& word : inputWords) {
        char punctuation;
        string cleanWord = removePunctuation(word, punctuation);
        wordLengths.push_back(cleanWord.length());
        punctuations.push_back(punctuation);
    }

    vector<list<string>> wordGroups;

    for (int i = 0; i < inputWords.size(); ++i) {
        int wordLength = wordLengths[i];

        if (wordGroups.size() < wordLength + 1) {
            wordGroups.resize(wordLength + 1);
        }
        wordGroups[wordLength].push_back(inputWords[i]);
    }

    vector<string> outputWords(inputWords.size());

    for (int i = 0; i < inputWords.size(); ++i) {
        int wordLength = wordLengths[i];
        outputWords[i] = wordGroups[wordLength].back();
        wordGroups[wordLength].pop_back();
    }

    for (int i = 0; i < outputWords.size(); ++i) {
        string outWord = outputWords[i];
        char originalPunctuation = punctuations[i];
        char swappedPunctuation = '\0';
        string cleanWord = removePunctuation(outWord, swappedPunctuation);

        if (i == 0 || (inputWords[i - 1].back() == '.' || inputWords[i - 1].back() == '?' || inputWords[i - 1].back() == '!')) {
            cleanWord[0] = toupper(cleanWord[0]);
        }
        else {
            cleanWord[0] = tolower(cleanWord[0]);
        }

        cout << cleanWord;

        if (originalPunctuation != '\0') {
            cout << originalPunctuation;
        }

        if (i < outputWords.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;

    return 0;
}
