#include <iostream>
using namespace std;

int mat[5][5];
int ans[5][5] = {0};
bool rowDone[5] = {0}, colDone[5] = {0}, diagDone[2] = {0};

int check(int u, int v, int count) {
    if (!rowDone[u]) {
        bool ok = true;
        for (int i = 0; i < 5; i++) if (!ans[u][i]) ok = false;
        if (ok) { count++; rowDone[u] = true; }
    }
    if (!colDone[v]) {
        bool ok = true;
        for (int j = 0; j < 5; j++) if (!ans[j][v]) ok = false;
        if (ok) { count++; colDone[v] = true; }
    }
    if (u == v && !diagDone[0]) {
        bool ok = true;
        for (int i = 0; i < 5; i++) if (!ans[i][i]) ok = false;
        if (ok) { count++; diagDone[0] = true; }
    }
    if (u + v == 4 && !diagDone[1]) {
        bool ok = true;
        for (int i = 0; i < 5; i++) if (!ans[i][4 - i]) ok = false;
        if (ok) { count++; diagDone[1] = true; }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 5; i++) 
        for (int j = 0; j < 5; j++) 
            cin >> mat[i][j];

    int count = 0;
    int answer = -1;
    
    for (int n = 1; n <= 25; n++) {
        int x; cin >> x;
        for (int j = 0; j < 5; j++) 
            for (int k = 0; k < 5; k++) {
                if (x == mat[j][k]) {
                    ans[j][k] = 1;
                    count = check(j, k, count);
                    if (count >= 3 && answer == -1) {
                        answer = n;
                    }
                }
            }
    }
    cout << answer;
    return 0;
}