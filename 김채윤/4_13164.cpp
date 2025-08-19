#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    if (K >= N) {
        cout << 0;
        return 0;
    }

    priority_queue<long long> pq;
    long long sum = 0;
    for (int j = 0; j < N - 1; j++) {
        pq.push(v[j + 1] - v[j]);
        sum += v[j + 1] - v[j];
    }
    for (int k = 0; k < K - 1; k++) {
        sum -= pq.top();
        pq.pop();
    }

    cout << sum;

    return 0;
}