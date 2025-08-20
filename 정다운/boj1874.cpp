#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    int countPlus = 0;
    int countMinus = 0;
    cin >> n;
    vector<int> vecInt(n);
    vector<int> vecTemp(n);
    vector<char> vecChar(1);
    stack<int> stackInt;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vecInt[i] = temp;
    }
    stackInt.push(++countPlus);
    vecChar[0] = '+';

    int i = 0;
    while (vecInt != vecTemp)
    {
        if (stackInt.empty() || vecInt[i] > stackInt.top())
        {
            stackInt.push(++countPlus);
            vecChar.push_back('+');
        }
        else if (vecInt[i] == stackInt.top())
        {
            countMinus++;
            vecTemp[i++] = stackInt.top();
            stackInt.pop();
            vecChar.push_back('-');
        }
        else if ((stackInt.top() > vecInt[i]) || (stackInt.top() < vecInt[i] && countPlus > n))
        {
            cout <<"NO"<<'\n';
            return 0;
        }
    }

    for (int i = 0; i < vecChar.size(); i++)
    {
        cout << vecChar[i] << '\n';
    }
}