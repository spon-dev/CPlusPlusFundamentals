#include <iostream>
using namespace std;

int main()
{
	size_t counts[10] = { 0 };
	int inputSize;
	cin >> inputSize;

	for (size_t c = 0; c < inputSize; c++)
	{
		int curNumber;
		cin >> curNumber;

		counts[curNumber]++;
	}
	
	//find the max value in the list of counts
	size_t maxValue = counts[0];
	for (size_t c = 1; c < 10; c++)
	{
		if (counts[c] > maxValue)
			maxValue = counts[c];
	}
	
	//print out all digits, which are found maxValue times
	for (size_t c = 0; c < 10; c++)
	{
		if (counts[c] == maxValue)
		{
			cout << c << ' ';
		}
			

	}
	cout << endl;
	return 0;
}