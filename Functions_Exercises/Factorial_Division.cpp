#include <iostream>
using namespace std;

double Factorial(double n) 
{
    double factorial = 1.0;
    for (int i = n; i > 0; i--)
    {
        factorial *=i;
    }
    return factorial;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << Factorial(a) / Factorial(b) << endl;
    return 0;
}

