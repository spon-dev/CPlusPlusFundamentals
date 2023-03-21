#include <iostream>
using namespace std;

extern void outputZeroTo19(int digit);



void outputThousands(int thousands)
{
	outputZeroTo19(thousands);
	cout << " thousand";
}
void outputHundreds(int hundreds)
{
	outputZeroTo19(hundreds);
	cout <<" hundred";
}

void outputZeroTo19(int digit)
{
	switch(digit)
	{
	case 0:cout << "zero";break;
	case 1:cout << "one"; break;
	case 2:cout << "two"; break;
	case 3:cout << "three"; break;
	case 4:cout << "four"; break;
	case 5:cout << "five"; break;
	case 6:cout << "six"; break;
	case 7:cout << "seven"; break;
	case 8:cout << "eight"; break;
	case 9:cout << "nine"; break;
	case 10:cout << "ten"; break;
	case 11:cout << "eleven"; break;
	case 12:cout << "twelve"; break;
	case 13:cout << "thirteen"; break;
	case 14:cout << "fourteen"; break;
	case 15:cout << "fifteen"; break;
	case 16:cout << "sixteen"; break;
	case 17:cout << "seventeen"; break;
	case 18:cout << "eighteen"; break;
	case 19:cout << "nineteen"; break;
	}
}



void outputDoubleDigit(int zeroto99)
{
	int decimals = zeroto99 / 10;// 89 => 8
	int singles = zeroto99 % 10;//89 => 9;
	switch (decimals)
	{
	case 2:cout << "twenty"; break;
	case 3:cout << "thirty"; break;
	case 4:cout << "fourty"; break;
	case 5:cout << "fifty"; break;
	case 6:cout << "sixty"; break;
	case 7:cout << "seventy"; break;
	case 8:cout << "eighty"; break;
	case 9:cout << "ninety"; break;
	}
	if (singles)
	{
		cout << " ";
		outputZeroTo19(singles);
	}

}


void outputZeroTo99(int zeroto99)
{
	
	if (zeroto99 <= 19)
	{
		outputZeroTo19(zeroto99);
	}
	else
	{
		outputDoubleDigit(zeroto99);
	}
}

int main()
{
	int number;
	cin >> number;
	
	int thousands = number / 1000; // 0...9
	int hundreds = (number%1000) / 100; //3539 345 =>3
	int zeroto99 = (number % 100);
	 
	if (thousands != 0)
	{
		outputThousands(thousands);
	}
	if (hundreds != 0)
	{
		if (number>999)
		{
			cout << ' ';
		}
		outputHundreds(hundreds);
	}
	if (zeroto99)//if zeroto99 is different than 0

	{
		if (number > 99)
			cout << ' ';
		outputZeroTo99(zeroto99);
	}

	if (!number)
		cout << "zero" << endl;  

	cout << endl;

	return 0;
}

