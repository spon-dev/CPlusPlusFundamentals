#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>

using namespace std;

int main()
{

    //  03. Ultimate Reverse words (it's over 9000)

    vector<string> vecStr;
    vector<string> vecSymb;

    vector<int> vecOrder;

    string finalSent, originalSent;

    while (true)
    {
        string strInput;
        getline(cin, strInput);

        if (strInput == "end")
        {
            break;
        }
        else if (originalSent.empty())
        {
            originalSent += strInput;
        }
        else
        {
            originalSent += string(" ") + strInput;
        }
    }

    //cout << originalSent << endl; // za test
    //cout << originalSent.length() << endl; // za test

    istringstream istrSent(originalSent);
    string strWord;

    while (istrSent >> strWord)
    {
        string strPunc;

        for (int idx = strWord.length() - 1; idx >= 0; idx--)
        {
            char charLastSymb = strWord[idx];
            bool isNotPunctuation = charLastSymb >= 'A' && charLastSymb <= 'Z' || charLastSymb >= 'a' && charLastSymb <= 'z'
                || charLastSymb == '+' || charLastSymb == '-';
            if (!isNotPunctuation)
            {
                strWord.erase(idx, 1);
                strPunc += charLastSymb;
                continue;
            }
            break;
        }
        vecStr.push_back(strWord);
        vecSymb.push_back(strPunc);
    }

    vecOrder.reserve(vecStr.size());
    vecOrder.assign(vecStr.size(), -1);

    for (int idx1 = 0; idx1 < vecStr.size(); idx1++)
    {
        bool flagMatch = false;
        for (int idx2 = vecStr.size() - 1; idx2 > idx1; idx2--)
        {
            if (vecStr[idx1].length() == vecStr[idx2].length() && vecOrder[idx2] == -1)
            {
                if (vecStr[idx1] != "-" && vecStr[idx2] != "-")
                {
                    vecOrder[idx1] = idx2;
                    vecOrder[idx2] = idx1;
                    flagMatch = true;
                    break;
                }

            }
        }
        if (!flagMatch && vecOrder[idx1] == -1)
        {
            vecOrder[idx1] = idx1;
        }
    }


    for (size_t idx = 0; idx < vecOrder.size(); idx++)
    {
        if (idx != 0)
        {
            bool checkCapital = vecStr[vecOrder[idx]][0] >= 'A' && vecStr[vecOrder[idx]][0] <= 'Z';
            if (checkCapital)
            {
                vecStr[vecOrder[idx]][0] += 32;
            }

            finalSent += " ";

        }
        else
        {
            bool checkCapital = vecStr[vecOrder[idx]][0] >= 'a' && vecStr[vecOrder[idx]][0] <= 'z';
            if (checkCapital)
            {
                vecStr[vecOrder[idx]][0] -= 32;
            }
        }
        finalSent += vecStr[vecOrder[idx]];
        finalSent += vecSymb[idx];
    }

    cout << finalSent << endl;
    
    return 0;
}
