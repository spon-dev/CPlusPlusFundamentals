#include <iostream>
using namespace std;

void printTriangle(int n)
{
    // print the top half of the triangle    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }
    // print the bottom half of the triangle
    for (int i=n-1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    printTriangle(n);

    return 0;
}
