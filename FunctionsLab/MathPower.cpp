#include <iostream>
using namespace std;

double mathPower(double base, int exp) 
{
	double result = 1;
	bool negativeExp = false;
	if (exp < 0) 
	{
		negativeExp = true;
		exp *= -1;
	}
	for (int i = 0; i < exp; i++)
	{
		result *= base;
	}
	if (negativeExp) 
	{
		result = 1 / result;
	}
	return result;
}
int main()
{
	double a, b;
	cin >> a >> b;
	cout<<mathPower(a,b);

	return 0;
}


