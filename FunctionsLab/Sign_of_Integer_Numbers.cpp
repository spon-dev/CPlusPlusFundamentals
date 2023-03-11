#include <iostream>
using namespace std;

void printSign(int n)
{
	if (n > 0)
	{
		cout << "The number "<<n<<" is positive." << endl;
	}
	else if(n<0)
	{
		cout << "The number " << n << " is negative." << endl;
	}
	else
	{
		cout << "The number " << n << " is zero." << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	printSign(n);

	return 0;
}


