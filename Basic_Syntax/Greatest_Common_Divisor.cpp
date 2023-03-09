#include <iostream>
using namespace std;

int main()
{

    int a, b, temp;

    cin >> a >> b;

    if (a < b)


    {
        temp = a;

        a = b;

        b = temp;

    }

    while (b > 0)
    {

        temp = b;
        b = a % b;
        a = temp;

    }

    cout << a << endl;

    return 0;
}


