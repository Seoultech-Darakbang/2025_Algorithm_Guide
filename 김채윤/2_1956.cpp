#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> arr(V + 1, vector<int>(V + 1, INF));

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    for (int j = 1; j <= V; j++) arr[j][j] = 0;

    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            if (arr[i][k] == INF) continue;
            for (int j = 1; j <= V; j++) {
                if (arr[k][j] == INF) continue;
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }

    int answer = INF;

    for (int l = 1; l <= V; l++) {
        for (int i = 1; i <= V; i++) {
            if (l == i) continue;
            answer = min(answer, arr[l][i] + arr[i][l]);
        }
    }

    if (answer == INF) cout << -1;
    else cout << answer;

    return 0;
}