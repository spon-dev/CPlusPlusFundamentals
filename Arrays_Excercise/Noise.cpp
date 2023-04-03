#include <iostream>
#include<cmath>
#include<string>
using namespace std;


int main()
{
    int number = 0;

    while(true)
    {
        char c;
        cin >> c;

        if (c == '.')
        {
            break;
        }


        if (c >= '0' && c <= '9')
        {
            number = number * 10;
            number = number + (c - '0');
        }
    }
    
    cout << sqrt((double)number) << endl;

    return 0;
}

/*
   int number = 0;
    string str;
    getline(cin, str);

    for (size_t curIdx = 0; curIdx < str.length(); curIdx++)
    {
        char c = str[curIdx];
        if (c >= '0' && c <= '9')
        {
            number = number * 10;
            number = number + (c - '0');
        }
    }

    cout << sqrt((double)number) << endl;

    return 0;


*/
