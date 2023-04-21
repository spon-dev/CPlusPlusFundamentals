#include <iostream>
#include <cstdlib>
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

bool areEqual(int arr1[], int length1, int arr2[], int length2)
{
	if (length1 != length2)
		return false;

	for (size_t counter = 0; counter < length1; counter++)
	{
		if (arr1[counter]  != arr2[counter])
		{
			return false;
		}
		
	}
	return true;
}

int main()
{
	int arr1[maxArraySize], arr2[maxArraySize];
	int arr1Size, arr2Size;

	enterArray(arr1, arr1Size);
	enterArray(arr2, arr2Size);

	if (areEqual(arr1, arr1Size, arr2, arr2Size))
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "Not equal" << endl;
	}
		


	return 0;
}


