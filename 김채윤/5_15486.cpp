#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, long long>> v(N + 1);

    for (int i = 1; i <= N; i++) cin >> v[i].first >> v[i].second;

    vector<long long> money(N + 2, 0);

    for (int i = 1; i <= N; i++) {
        money[i] = max(money[i], money[i-1]); 
        int next = i + v[i].first;
        if (next <= N + 1) {
            money[next] = max(money[next], money[i] + v[i].second); 
        }
    }

    cout << max(money[N], money[N+1]);

    return 0;
}