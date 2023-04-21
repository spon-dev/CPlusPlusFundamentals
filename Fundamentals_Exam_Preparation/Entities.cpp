#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void readData(const string & buffer, vector<string>& data)
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

   vector<string> linearData;

   while (true)
   {
	   string buffer;
	   getline(cin, buffer);

	   if (buffer == "end")
	   {
		   break;
	   }

	   linearData.reserve(linearData.size() + numColumns);
	   readData(buffer, linearData);

   }

   string searchColumn;

   getline(cin, searchColumn);

   vector<string>::iterator itColumn = find(columns.begin(), columns.end(), searchColumn);
   size_t searchColIdx = itColumn - columns.begin();

   vector<string>colValues;
   colValues.reserve(linearData.size() / numColumns);
   for (size_t curIdx = searchColIdx; curIdx < linearData.size(); curIdx+=numColumns)
   {
	   colValues.push_back(linearData[curIdx]);
   }

   sort (colValues.begin(), colValues.end());

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

