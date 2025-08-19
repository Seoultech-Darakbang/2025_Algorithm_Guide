#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> sensor(N);
    for (int i = 0; i < N; ++i) cin >> sensor[i];

    if (K >= N) {            
        cout << 0 << '\n';
        return 0;
    }

    sort(sensor.begin(), sensor.end());

    priority_queue<int> pq;
    long long total = 0;   
    for (int i = 1; i < N; ++i) {
        int gap = sensor[i] - sensor[i-1];
        pq.push(gap);
        total += gap;
    }

    for (int i = 0; i < K-1; ++i) {
        total -= pq.top();
        pq.pop();
    }

    cout << total << '\n';
    return 0;
}