#include <iostream>
#include<sstream>
using namespace std;

bool compareArray(istream& arr1, istream& arr2)
{
    while (arr1&&arr2)
    {
       // compare current number
        int a1Number, a2Number;
        arr1 >> a1Number;
        arr2 >> a2Number;

        if (a1Number != a2Number)
            return false;

    }
    return (bool)arr1 == (bool)arr2;
}

int main()
{
    string arr1str, arr2str;

    getline(cin, arr1str);
    getline(cin, arr2str);

    istringstream arr1(arr1str), arr2(arr2str);

    if (compareArray(arr1, arr2))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;



    return 0;
}


