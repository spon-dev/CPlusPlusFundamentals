#include <iostream>
using namespace std;
const int maxArraySize = 100;

void enterArray(int arr[], int& arrSize)
{
	cin >> arrSize;

	if (arrSize > maxArraySize)
	{
		cout << "Buffer too small. Needed: " << arrSize << endl;
		exit(1);
	}

	for (size_t c = 0; c < arrSize; c++)
	{
		cin >> arr[c];
	}
}
int arraySum(int arr[], int arrSize)
{
	int sum = 0;

	for (size_t c = 0; c < arrSize; c++)
	{
		sum += arr[c];
	}
	return sum;
}



int main()
{
	int arr[maxArraySize];
	int arrSize;

	enterArray(arr, arrSize);
	int average = arraySum(arr, arrSize) / arrSize;

	for (size_t c = 0; c < arrSize; c++)
	{
		if (arr[c] >= average)
		{
			cout << arr[c] << ' ';
		}
	}
	
	cout << endl;

	return 0;
}


