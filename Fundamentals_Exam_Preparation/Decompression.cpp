#include <iostream>
#include <sstream>
using namespace std;

string decompress(const string& input)
{
	ostringstream output;

	int number = 0; //here, we will store the number of times a letter to be repeated

	for (char c : input)
	{

		if (c >= '0' && c <= '9')
		{
			//we have a number
			number = number * 10;
			number += (c - '0');
			continue;
		}

		if (number)
		{
			string strTemp(number, c);
			output << strTemp;
			number = 0;
		}
		else
			output << c;
	}

	return output.str();
}

int main()
{
	string input;
	getline(cin, input);

	cout << decompress(input) << endl;
	
	return 0;
}

