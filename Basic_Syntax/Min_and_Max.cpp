#include <iostream>
#include <climits>
using namespace std;

int main()
{
   
	int n,k;

	int min = INT_MAX;
	int max = INT_MIN;

	cin >> n;

	for (int i = 0; i < n; i++)

	{
		cin >> k;

		if (k < min)
		{

			min = k;
		}

		if (k > max)
		{

			max = k;

		}

		



	}
	

	cout << min << " " << max << endl;
	
	return 0;
}


