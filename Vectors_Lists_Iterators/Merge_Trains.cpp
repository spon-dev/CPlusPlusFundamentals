#include <iostream>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

void readList(istream& iStr, list<int>& output)
{
    int buf;
    while (iStr>>buf)
    {
        output.push_back(buf);
    }

}

void readList(const string& buf, list<int>& output)
{
    istringstream iStr(buf);
    readList(iStr, output);
}

void readTrain(istream& iStr, list<int>& train)

{
    string trainStr;
    getline(iStr, trainStr);
    readList(trainStr, train);
}

void mergeFrom(list<int>& finalTrain, list<int>::iterator& it, string& mergeRes, char train)
{
    mergeRes.insert(mergeRes.begin(), train);
    finalTrain.push_back(*it);
    it++;
}

int main()
{
    list <int> trainA, trainB;

    readTrain(cin, trainA);
    readTrain(cin, trainB);

    string mergeRes;
    list<int> finalTrain;

    list<int>::iterator itA = trainA.begin(), itB = trainB.begin();
    while (itA != trainA.end() || itB != trainB.end() )
    {
        if (itA == trainA.end()) //if trainA is over, there is only trainB;
            mergeFrom(finalTrain, itB, mergeRes, 'B');
        else if (itB == trainB.end())
            mergeFrom(finalTrain, itA, mergeRes, 'A');
        else
        {
            if(*itA > *itB)
                mergeFrom(finalTrain, itA, mergeRes, 'A');
            else
                mergeFrom(finalTrain, itB, mergeRes, 'B');

        }
    }

    cout << mergeRes << endl;
    for (int c : finalTrain)
    {
        cout << c << " ";  
    }
    cout << endl;
    return 0;
}



