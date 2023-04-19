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

	size_t seq_length = 1;
	int longestElement= arr[0];

	size_t cur_length = 1;
	int curLongest=arr[0];

	for (size_t c = 1; c < arrSize; c++)
	{
		if (arr[c] == curLongest)
			cur_length++;
		else
		{
			cur_length = 1;
			curLongest = arr[c];
		}
		if (cur_length >= seq_length)
		{
			seq_length = cur_length;
			longestElement = curLongest;
		}
	

	}

	for (size_t c = 0; c < seq_length; c++)
	{
		cout << longestElement << ' ';
		
	}
	cout << endl;
	return 0;
}


