//The solution is not complete. It gives incorrect output. I will fix it when I have time to debug it.

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;

bool is_punctuation(char ch) {
    return ispunct(static_cast<unsigned char>(ch));
}

string process_word(const string& word) {
    string result;
    for (char ch : word) {
        if (!is_punctuation(ch)) {
            result += ch;
        }
    }
    return result;
}

int main() {
    vector<string> lines;
    string line;

    while (getline(cin, line)) {
        if (line == "end") {
            break;
        }
        lines.push_back(line);
    }

    for (const string& line : lines) {
        vector<string> words;
        stringstream ss(line);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        map<size_t, vector<string>> size_groups;

        for (const string& w : words) {
            size_groups[process_word(w).size()].push_back(w);
        }

        for (auto& group : size_groups) {
            reverse(group.second.begin(), group.second.end());
        }

        map<size_t, size_t> group_indices;

        for (size_t k = 0; k < words.size(); ++k) {
            const string& w = words[k];
            size_t word_size = process_word(w).size();

            if (size_groups.count(word_size) && group_indices[word_size] < size_groups[word_size].size()) {
                string result_word = size_groups[word_size][group_indices[word_size]];
                string result_word_punctuated;

                for (size_t i = 0, j = 0; i < w.size(); ++i) {
                    if (!is_punctuation(w[i])) {
                        char new_char = (k == 0 || (i > 0 && w[i - 1] == ' ' && words[k - 1].back() == '.')) ? toupper(result_word[j]) : tolower(result_word[j]);
                        result_word_punctuated += new_char;
                        j++;
                    }
                    else {
                        result_word_punctuated += w[i];
                    }
                }

                cout << result_word_punctuated;

                group_indices[word_size]++;

                if (k != words.size() - 1) {
                    cout << ' ';
                }
            }
        }
        cout << endl;
    }

    return 0;
}
