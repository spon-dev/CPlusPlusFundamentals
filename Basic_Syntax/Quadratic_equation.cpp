#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	double D = pow(b,2) - 4 * a * c;
	double x1 = (-b + sqrt(D)) / (2 * a);
	double x2 = (-b - sqrt(D)) / (2 * a);
	if (D < 0)
	{

		cout << "no roots" << endl;
	}

	else if (D == 0)
	{
		cout << x1 << endl;
	}

	else
	{

		cout << x1 << " " << x2 << endl;

	}

	return 0;
}


