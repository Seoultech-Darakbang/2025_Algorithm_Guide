#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, idx;
priority_queue<int, vector<int>, greater<int>> t;

void time(vector<pair<int,int>>& v) {
    if (idx >= N) return;

    for (int i = idx; i < N; ++i) {
        int s = v[i].first;
        int e = v[i].second;

        if (!t.empty() && t.top() <= s) t.pop();

        t.push(e);
    }
    idx = N; 
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> N;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(),
    [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first != b.first) return a.first < b.first; 
        return a.second < b.second;                 
    });

    idx = 0;
    time(v);

    cout << t.size();

    return 0;
}