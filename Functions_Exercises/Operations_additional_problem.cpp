#include <iostream>
using namespace std;

void isAddition(int a, int b)
{
	cout << a + b << endl;
}

void isSubtraction(int a, int b)
{
	cout << a - b << endl;
}

void isMultiplication(int a, int b)
{
	cout << a * b << endl;
}

void isDivision(int a, int b)
{
	if (b == 0)
	{
		cout << "Can't divide by zero." << endl;
	}
	else
	{
		cout << a / b << endl;
	}
}

int main()
{
	int a, b;
	char operation;

	
	
		if (cin >> a >> b)
		{
			while (true)
			{
				cin >> operation;

				if (operation == '+')
				{
					isAddition(a, b);
				}
				else if (operation == '-')
				{
					isSubtraction(a, b);
				}
				else if (operation == '*')
				{
					isMultiplication(a, b);
				}
				else if (operation == '/')
				{

					isDivision(a, b);
				}
				else
				{
					cout << "try again" << endl;
				}

			}

		}
		else
		{
			cout << "Invalid input, please enter two numbers." << endl;
			return 1;
		}

	return 0;
}
