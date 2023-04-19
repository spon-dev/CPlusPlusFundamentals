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



	return 0;
}


