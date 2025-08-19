#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;

int N;

int Dijkstra(vector<pair<int, int>> v[], int n, int m) {
    vector<int> D(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    D[n] = 0;
    pq.push({0, n});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist > D[now]) continue;

        for (auto [next, cost] : v[now]) {
            if (D[next] > D[now] + cost) {
                D[next] = D[now] + cost;
                pq.push({D[next], next});
            }
        }
    }

    return D[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int E;
    cin >> N >> E;
    vector<pair<int, int>> v[N + 1];

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    int sum1 = Dijkstra(v, 1, v1);
    int sum2 = Dijkstra(v, v2, N);
    int sum3 = Dijkstra(v, v1, v2);
    int sum4 = Dijkstra(v, 1, v2);
    int sum5 = Dijkstra(v, v1, N);

    if (sum3 >= INF || ((sum1 >= INF || sum2 >= INF) && (sum4 >= INF || sum5 >= INF))) {
        cout << -1;
        return 0;
    }
    if (sum1 + sum2 > sum4 + sum5) cout << sum4 + sum5 + sum3;
    else cout << sum1 + sum2 + sum3;

    return 0;
}