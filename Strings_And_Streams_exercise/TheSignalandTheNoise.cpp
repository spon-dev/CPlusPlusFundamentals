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

    int max = INT_MIN;

    string token;

    while (iStr>>token)
    {
        
        istringstream istrToken(token);

        int number = 0;
        char c;

        while (istrToken>>c)
        {
            if (isdigit(c))
            {
                number *= 10;
                number += (c - '0');
            }

        }
        if (number > max)
            max = number;

    }

    cout << max << endl;
    return 0;
}

