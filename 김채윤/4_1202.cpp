#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    priority_queue<pair<long long,long long>, 
                vector<pair<long long,long long>>, 
                greater<pair<long long,long long>>> j;
    priority_queue<long long, vector<long long>, greater<long long>> b;

    for (int i = 0; i < N; i++) {
        long long m, v;
        cin >> m >> v;
        j.push({m, v});
    }
    for (int i = 0; i < K; i++) {
        long long c;
        cin >> c;
        b.push(c);
    }

    long long sum = 0;
    priority_queue<long long> candidate;

    while (!b.empty()) {
        long long cap = b.top();
        b.pop();

        while (!j.empty() && j.top().first <= cap) {
            candidate.push(j.top().second);
            j.pop();
        }

        if (!candidate.empty()) {
            sum += candidate.top();
            candidate.pop();
        }
    }

    cout << sum << "\n";
    return 0;
}