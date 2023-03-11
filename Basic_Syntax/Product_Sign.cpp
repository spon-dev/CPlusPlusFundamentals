#include <iostream>
using namespace std;

bool isPositive(double a)
{

	return a > 0;

}

int main()
{
	double a, b, c;
	cin >> a >> b >> c;


	if (a == 0 || b == 0 || c == 0)
	{
		cout << "+";

		return 0;
	}

	/*
	bool isPositiveA = a > 0;

	bool isPositiveB = b > 0;

	

	bool output = (isPositiveA == isPositiveB);

	isPositiveB = c > 0;

	output = (output == isPositiveB);

	*/

	bool output = (isPositive(a) == isPositive(b));

	output = (output == isPositive(c));


	if (output == true)
	{

		cout << "+";

	}

	else
	{
		cout << "-";
	}


	return 0;

}


