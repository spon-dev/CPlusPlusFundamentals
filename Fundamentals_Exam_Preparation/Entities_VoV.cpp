#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void readData(const string& buffer, vector<string>& data)
{
	istringstream iStr(buffer);
	string strData;
	while (iStr >> strData)
	{
		data.push_back(strData);
	}
}

//reads a whole line with data from the console
//e.g. "Joro 25 unknown 87"

void readData(istream& input, vector<string>& data)
{
	string buffer;
	getline(input, buffer);

	readData(buffer, data);

}

int main()
{
	vector<string> columns;

	readData(cin, columns);
	size_t numColumns = columns.size();

	vector<vector <string> > data;

	while (true)
	{
		string buffer;
		getline(cin, buffer);

		if (buffer == "end")
		{
			break;
		}

		vector<string> curRow;
		curRow.reserve(numColumns);

		readData(buffer, curRow);
		data.push_back(curRow);

	}

	string searchColumn;

	getline(cin, searchColumn);

	vector<string>::iterator itColumn = find(columns.begin(), columns.end(), searchColumn);
	size_t searchColIdx = itColumn - columns.begin();

	vector<string>colValues;
	colValues.reserve(data.size());

	for (size_t curIdx = 0; curIdx < data.size(); curIdx ++)
	{
		vector<string>& curRow = data[curIdx];
		colValues.push_back(curRow[searchColIdx]);
	}

	sort(colValues.begin(), colValues.end());

	string mostCommon;
	size_t mostCommonSize = 0;

	string currValue = colValues[0];
	size_t currValueSize = 1;


	for (vector<string>::iterator it = colValues.begin() + 1; it != colValues.end(); it++)
	{
		if (*it == currValue)
			currValueSize++;
		else
		{
			if (currValueSize > mostCommonSize)
			{
				mostCommonSize = currValueSize;
				mostCommon = currValue;
			}

			currValue = *it;
			currValueSize = 1;
		}
	}


	if (currValueSize > mostCommonSize)
	{
		mostCommonSize = currValueSize;
		mostCommon = currValue;
	}



	cout << mostCommon << " " << mostCommonSize << endl;
	return 0;
}

