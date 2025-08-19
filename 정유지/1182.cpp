#include <iostream>
using namespace std;

const int MAX = 20;
int n, s, cnt = 0;
int sequence[MAX];

void search(int idx, int sum){
    if(sum + sequence[idx] == s)  cnt++;
    // 마지막 원소까지 탐색한 경우
    if(idx >= n-1)  return;

    // 현재 원소를 선택하지 않은 경우
    search(idx+1, sum);
    // 현재 원소를 선택한 경우
    search(idx+1, sum + sequence[idx]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> s;

    for(int i = 0; i < n; i++)
        cin >> sequence[i];

    search(0, 0);

    cout << cnt << endl;

    return 0;
}
