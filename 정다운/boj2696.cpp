#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int t, m;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m;
        multiset<int> setArr; //
        vector<int> vecArr;
        for (int j = 0; j < m; j++) {
            int n;
            cin >> n;
            setArr.insert(n); // multiset은 오름차순으로 정렬됨
            if (j % 2 == 0) { // 홀수값을 읽을 때 vecTemp에 setArr 펼쳐서 vecArr에 중앙값 insert
                vector<int> vecTemp(setArr.begin(), setArr.end());
                vecArr.insert(vecArr.end(), vecTemp[j / 2]);
            }
        }
        cout << (m + 1) / 2 << "\n"; // 홀수값을 읽는 횟수 == 중앙값을 출력하는 횟수
        for (int j = 1; j < vecArr.size() + 1; j++) {
            cout << vecArr[j - 1] << " ";
            if (j % 10 == 0 && j != 0) {
                cout << "\n";
            }
        }
        cout << "\n";
    }
}