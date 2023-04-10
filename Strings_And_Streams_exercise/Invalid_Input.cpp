#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string input;
	getline(cin, input);

	istringstream iStr(input);

	ostringstream errors;

	int sum = 0;
	string token;

	while (iStr>>token)
	{
		istringstream iStrConvert(token);
		int number;
		iStrConvert >> number;
		if (iStrConvert)
			sum += number;
		else
			errors << token << ' ';

	}
	cout << sum << endl;
	cout << errors.str() << endl;
	
	return 0;
}


