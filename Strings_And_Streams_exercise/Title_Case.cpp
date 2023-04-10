#include <iostream>
#include <sstream>
using namespace std;

string capitalize(const string& input)
{
	ostringstream oStr;

	bool capitalize = true;

	for (size_t idx = 0; idx < input.length(); idx++)
	{
		char c = input[idx];
		bool isSmallLetter = (c >= 'a' && c <= 'z');
		bool isCapitalLetter = (c >= 'A' && c <= 'Z');
		if (isSmallLetter || isCapitalLetter)
		{
			if (capitalize)
			{
				if (isSmallLetter)
					c -= 32;//turn 'a' into 'A' by subtracting 32-see an ASCII table for reference;
				capitalize = false;
			}

		}
		else
			capitalize = true;
		oStr << c;

	}
	return oStr.str();
}

int main()
{
	string input;
	getline(cin, input);

	cout << capitalize(input) << endl;

	return 0;
}


