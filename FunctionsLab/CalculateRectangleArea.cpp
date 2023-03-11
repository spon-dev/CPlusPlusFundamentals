#include <iostream>
using namespace std;

double calculateRectangleArea (double a, double b)
{
    
    return a*b;
}

int main()
{
    double a, b;

    cin >> a >> b;

    cout << calculateRectangleArea(a, b) << endl;

    return 0;
}

