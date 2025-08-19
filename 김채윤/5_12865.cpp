#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> v(N + 1);
    for (int i = 1; i <= N; i++) cin >> v[i].first >> v[i].second;

    vector<vector<int>> bag(N+1, vector<int>(K+1, 0));

    for (int j = 1; j <= N; j++) { // 물건 번호
        for (int k = 1; k <= K; k++) { // 용량
            if (v[j].first > k) bag[j][k] = bag[j - 1][k];
            else {
                bag[j][k] = max(bag[j - 1][k], bag[j - 1][k - v[j].first] + v[j].second);
            }
        }
    }

    cout << bag[N][K];

    return 0;
}