#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void cantor(vector<char> str)
{
    vector<char> tempStr1(str.size() / 3), tempStr2(str.size() / 3), tempStr3(str.size() / 3);
    if (find(str.begin(), str.end(), '-') != str.end())
    {
        fill(tempStr1.begin(), tempStr1.end(), '-');
        fill(tempStr2.begin(), tempStr2.end(), ' ');
        tempStr3 = tempStr1;
    }
    else
    {
        fill(tempStr1.begin(), tempStr1.end(), ' ');
        tempStr2 = tempStr1;
        tempStr3 = tempStr1;
    }

    if (tempStr1.size() != 1)
    {
        cantor(tempStr1);
        cantor(tempStr2);
        cantor(tempStr3);
    }
    else
    {
        cout << tempStr1[0] << tempStr2[0] << tempStr3[0];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n)
    {
        if(n==0) {
            cout<<'-'<<'\n';
            continue;
        }
        vector<char> str(pow(3, n), '-');
        cantor(str);
        cout<<'\n';
    }
}