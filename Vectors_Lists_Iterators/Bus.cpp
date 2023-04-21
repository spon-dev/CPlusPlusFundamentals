#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MilitaryToMinutes(string& Str)
{
    int hour = (Str[0] - '0') * 10 + (Str[1] - '0') * 1;
    int minutes = (Str[2] - '0') * 10 + (Str[3] - '0') * 1;

    return hour * 60 + minutes;
}

int main()
{
    size_t buses;
    cin >> buses;
    cin.ignore();

    vector<int> busDepartures;
    busDepartures.reserve(buses);

    for (size_t curBus = 0; curBus < buses; curBus++)
    {
        string strMilitaryTime;
        cin >> strMilitaryTime;

        int curTime = MilitaryToMinutes(strMilitaryTime);
        busDepartures.push_back(curTime);
    }

    int trainDeparture;
    string trainDepartureStr;
    cin >> trainDepartureStr;

    trainDeparture = MilitaryToMinutes(trainDepartureStr);
    int bestBusDifference = INT_MAX;
    size_t bestBusIndex = 0;

    for (size_t curBus = 0; curBus < buses; curBus++)
    {
        int curBusArrival = busDepartures[curBus];
        int difference;
  /*
        if (trainDeparture >= curBusArrival)
            difference = trainDeparture - curBusArrival;
        else
        {
            difference = 1440 - curBusArrival;
            difference += trainDeparture;
        }
    */
      
        difference = trainDeparture - curBusArrival;
        if (difference<0)
            difference += (24 * 60);
            

        if (difference < bestBusDifference)
        {
            bestBusDifference = difference;
            bestBusIndex = curBus + 1;
        }

    }
    cout << bestBusIndex << endl;

    return 0;
}

