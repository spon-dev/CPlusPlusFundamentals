#include <iostream>
using namespace std;

string gradeToString(double grade)
{
	
	if (grade >= 2.0 && grade <= 2.99)
	{
		return "Fail";
	}
	else if (grade >= 3.0 && grade <= 3.49)
	{
		return "Poor";
	}
	else if (grade >= 3.50 && grade <= 4.49)
	{
		return "Good";
	}
	else if (grade >= 4.50 && grade <= 5.49)
	{
		return "Very good";
	}
	else if (grade >= 5.50 && grade <= 6.0)
	{
		return "Excellent";
	}

}

int main()
{
	double grade;
	cin >> grade;

	cout << gradeToString(grade) << endl;
		
	return 0;
}


