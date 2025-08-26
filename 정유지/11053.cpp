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
        dp[i] = 1;  // 자기 자신만 포함하는 경우의 길이 설정
    }

    int answer = 1;
    for(int i = 0; i < n; i++){
        int best = 1;  // i번째에 도달하는 최대 길이

        for(int j = 0; j < i; j++){
            if(sequence[j] < sequence[i]){
                if(dp[j] + 1 > best)
                    best = dp[j] + 1;
                dp[i] = best;
            }
        }

        answer = dp[i] > answer ? dp[i] : answer;
    }

    cout << answer << endl;
    return 0;
}
