#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void readVector(istream& iStr, vector<int>& output)
{
    int buf;
    while (iStr >> buf)
    {
        output.push_back(buf);
    }

}

void readVector(const string& buf, vector<int>& output)
{
    istringstream iStr(buf);
    readVector(iStr, output);
}

void readPipe(istream& iStr, vector<int>& pipe)

{
    string pipeStr;
    getline(iStr, pipeStr);
    readVector(pipeStr, pipe);
}


int main()
{
    vector<int> installation, checkup;
    size_t pipes;
    cin >> pipes;
    cin.ignore();

    installation.reserve(pipes);
    checkup.reserve(pipes);

    readPipe(cin, checkup);
    readPipe(cin, installation);

    for (size_t curPipe = 0; curPipe < pipes; curPipe++)
    {
       int decay = installation[curPipe] - checkup[curPipe];

       cout << installation[curPipe] / decay << " ";

    }
    cout << endl;

	return 0;
}


