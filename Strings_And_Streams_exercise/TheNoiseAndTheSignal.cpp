#include <iostream>
#include <sstream>
#include <climits>
#include <cctype>
using namespace std;

int main()
{
    string input;
    getline(cin, input);

    istringstream iStr(input);

    string maxString;

    string token;

    while (iStr >> token)
    {
        string curString;
        istringstream istrToken(token);
        
        char c;

        while (istrToken >> c)
        {
            if (!isdigit(c))
            {
                curString += c;
            }

        }
 
        if (curString.length() > maxString.length() )
        {
            maxString = curString;
        }
        else if (curString.length() == maxString.length() && curString<maxString)
        {
            maxString = curString;
        }

    }

    if (maxString.length())
        cout << maxString << endl;
    else
        cout << "no noise";
 


    return 0;
}
/*
int main() {
    string input;
    getline(cin, input);

    string noise;
    string max_noise = "";
    int max_length = 0;

    for (unsigned int i = 0; i < input.size(); i++) {
        char c = input[i];
        if (!isdigit(c)) {
            noise += c;
        }
        else {
            if (!noise.empty()) {
                if (noise.length() > max_length || (noise.length() == max_length && noise < max_noise)) {
                    max_noise = noise;
                    max_length = noise.length();
                }
                noise.clear();
            }
        }
    }

    // Check the last noise in the input if it's not empty
    if (!noise.empty()) {
        if (noise.length() > max_length || (noise.length() == max_length && noise < max_noise)) {
            max_noise = noise;
            max_length = noise.length();
        }
    }

    if (max_length == 0) {
        cout << "no noise" << endl;
    }
    else {
        cout << max_noise << endl;
    }

    return 0;
}
*/