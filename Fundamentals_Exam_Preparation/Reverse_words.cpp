#include <iostream>
#include <sstream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<string> words;
    string line, word;

    while (getline(cin, line)) {
        stringstream ss(line);

        while (ss >> word) {
            if (word == "end") {
                break;
            }
            words.push_front(word);
        }

        if (word == "end") {
            break;
        }
    }

    for (const string& w : words) {
        cout << w << ' ';
    }

    return 0;
}
