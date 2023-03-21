#include <iostream>
using namespace std;

int main()
{
	long number;
	cin >> number;
	unsigned long sumodd = 0;
	unsigned long sumeven = 0;
	
	
		while (number) //number is different than zero
		{
			int singles = number % 10;//1234 => 4

			if (singles%2==0)
				sumeven += singles;
			else
				sumodd += singles;

			number = number / 10;
		}

		cout << sumodd * sumeven << endl;
	return 0;
}


