#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) arr[i][i] = 0;

    for (int j = 0; j < k; j++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (arr[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (arr[k][j] == INF) continue;
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }

    int s;
    cin >> s;

    while (s--) {
        int x, y;
        cin >> x >> y;

        if (arr[x][y] == INF && arr[y][x] != INF) cout << 1 << "\n";
        else if (arr[x][y] != INF && arr[y][x] == INF) cout << -1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}