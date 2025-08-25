#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;    
    cin >> n >> k;

    vector<vector<int>> nations(n, vector<int>(4));
    for (int i = 0; i < n; i++) 
        cin >> nations[i][0] >> nations[i][1] >> nations[i][2] >> nations[i][3];
    

    // 메달을 기준으로 정렬
    sort(nations.begin(), nations.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[1] != b[1])  return a[1] > b[1];  // 금
            if(a[2] != b[2])  return a[2] > b[2];  // 은
            return a[3] > b[3];  // 동
    });

    int rank = 1;
    for(int i = 0; i < n; i++){
        if(i > 0){
            // 이전 국가와 메달이 다르면 순위 증가
            if(nations[i][1] != nations[i-1][1] ||
            nations[i][2] != nations[i-1][2] ||
            nations[i][3] != nations[i-1][3]){
                rank = i+1;
            }
        }

        if(nations[i][0] == k){
            cout << rank << endl;
            break;
        }
    }

    return 0;
}
