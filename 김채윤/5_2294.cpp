#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    for (int i = 0; i < n; i++) cin >> coin[i];

    vector<int> dp(k + 1, INF); 
    dp[0] = 0;

    for (int c : coin) {             
        for (int money = c; money <= k; money++) {
            dp[money] = min(dp[money], dp[money - c] + 1);
        }
    }

    if (dp[k] == INF) cout << -1;
    else cout << dp[k];
}