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




int main()
{
	int arr[maxArraySize];
	int arrSize;

	enterArray(arr, arrSize);
	
	for (size_t curMul = 0; curMul < arrSize; curMul++)
	{
		for (size_t cur = 0; cur < arrSize; cur++)
		{
			cout << arr[curMul] * arr[cur] << ' ';
		}
	}

	cout << endl;

	return 0;
}


