#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> sequence(n), dp(n);
    
    for(int i = 0; i < n; i++){
        cin >> sequence[i];
        dp[i] = sequence[i];  // 자기 자신으로 시작
    }

    int answer = 0;
    for(int i = 0; i < n; i++){
        int best = 0;  // dp[j]의 최댓값
        for(int j = 0; j < i; j++){
            if(sequence[j] < sequence[i])
                best = max(best, dp[j]);
        }

        dp[i] = sequence[i] + best;
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;
    return 0;
}
