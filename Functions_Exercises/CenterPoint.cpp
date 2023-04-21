#include <iostream>
#include <cmath>
using namespace std;

void closerToCenter(double x1, double y1, double x2, double y2)
{
	double distance_A = sqrt(pow(x1, 2) + pow(y1, 2));
	double distance_B = sqrt(pow(x2, 2) + pow(y2, 2));

	if (distance_A <= distance_B)
	{
		cout << "(" << x1 << ", " << y1 << ")" << endl;
	}
	else
	{
		cout << "(" << x2 << ", " << y2 << ")" << endl;
	}
}

int main()
{
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	closerToCenter(x1, y1, x2, y2);

	return 0;
}


