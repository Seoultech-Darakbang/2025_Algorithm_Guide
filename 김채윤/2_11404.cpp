#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, INF));

    for (int idx = 1; idx <= n; idx++) {
        mat[idx][idx] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a][b] = min(mat[a][b], c);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (mat[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (mat[k][j] == INF) continue;
                mat[i][j] = min(mat[i][k] + mat[k][j], mat[i][j]);
            }
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            if (mat[j][k] == INF) cout << 0 << " ";
            else cout << mat[j][k] << " ";
        }
        cout << "\n";
    }
    return 0;
}