#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector <char>& input)
{
    size_t br0Count = 0; //()
    size_t br1Count = 0; //[]
    size_t br2Count = 0; //{}

    for (vector <char>::iterator it = input.begin(); it != input.end(); it++)
    {
        switch(*it)
        { 
        case '{':
            if (br0Count || br1Count)
                return false;
            br2Count++;
            break;
        case '}':
            if (br0Count || br1Count)
                return false;
            if (br2Count <= 0)
                return false;
            br2Count--;
            break;
        case '[':
            if (br0Count)
                return false;
            br1Count++;
            break;
        case ']':
            if (br0Count)
                return false;
            if (br1Count <= 0)
                return false;
            br1Count--;
            break;
        case '(':
            br0Count++;
            break;
        case ')':
            if (br0Count <= 0)
                return false;
            br0Count--;
            break;
        }
 

    }
    return br0Count == 0 && br1Count == 0 && br2Count == 0;

}


int main()
{
    string strBuf;
    cin >> strBuf;

    vector <char> input;
    input.reserve(strBuf.size());

    for (char c : strBuf)
        input.push_back(c);

    cout << (isValid(input) ? "valid" : "invalid") << endl;

    return 0;
}


