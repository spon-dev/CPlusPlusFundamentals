#include <iostream>
#include <sstream>
using namespace std;

bool validExpression(istream& exprStr)
{
    int brackets = 0;

    char c;
    while (exprStr>>c)
    {
        switch (c)
        {
        case'(': brackets++;
            break;
        case')': 
            if (brackets)
            {
                brackets--;
            }
            else
            {
                return false;
                break;
            }
        }
    }

    return brackets == 0;
}


int main()
{
    string expression;
    getline(cin, expression);

    istringstream exprStr(expression);

    if (validExpression(exprStr))
        cout << "correct" << endl;
    else
        cout << "incorrect" << endl;

    return 0;
}


