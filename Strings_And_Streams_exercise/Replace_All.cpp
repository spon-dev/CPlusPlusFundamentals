#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string strSource;
    getline(cin, strSource);

    string strFind;
    getline(cin, strFind);

    string strReplace;
    getline(cin, strReplace);

    int foundIndex = strSource.find(strFind);

    while (foundIndex!=string::npos)
    {
        strSource.replace(foundIndex, strFind.length(), strReplace);
        
        foundIndex = strSource.find(strFind,foundIndex+strReplace.length());

    }

    cout << strSource << endl;

    return 0;
}


