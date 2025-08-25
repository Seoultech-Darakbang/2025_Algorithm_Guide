#include <iostream>
using namespace std;

int mat[20][20];
int win = 0;
int startX, startY;

void find1(int u, int v, int num, int count) { 
    if (u - 1 >= 1 && v + 1 <= 19 && mat[u - 1][v + 1] == num) {
        count++;
        if (count == 5) {
            if (u - 2 < 1 || v + 2 > 19 || mat[u - 2][v + 2] != num) {
                cout << num << "\n";
                cout << startX << " " << startY;
                win = num;
            }
            return;
        }
        find1(u - 1, v + 1, num, count);
    }
}

void find2(int u, int v, int num, int count) { 
    if (u + 1 <= 19 && mat[u + 1][v] == num) {
        count++;
        if (count == 5) {
            if (u + 2 > 19 || mat[u + 2][v] != num) {
                cout << num << "\n";
                cout << startX << " " << startY;
                win = num;
            }
            return;
        }
        find2(u + 1, v, num, count);
    }
}

void find3(int u, int v, int num, int count) { 
    if (v + 1 <= 19 && mat[u][v + 1] == num) {
        count++;
        if (count == 5) {
            if (v + 2 > 19 || mat[u][v + 2] != num) {
                cout << num << "\n";
                cout << startX << " " << startY;
                win = num;
            }
            return;
        }
        find3(u, v + 1, num, count);
    }
}

void find4(int u, int v, int num, int count) { 
    if (u + 1 <= 19 && v + 1 <= 19 && mat[u + 1][v + 1] == num) {
        count++;
        if (count == 5) {
            if (u + 2 > 19 || v + 2 > 19 || mat[u + 2][v + 2] != num) {
                cout << num << "\n";
                cout << startX << " " << startY;
                win = num;
            }
            return;
        }
        find4(u + 1, v + 1, num, count);
    }
}

int main() {
    for (int i = 1; i <= 19; i++)
        for (int j = 1; j <= 19; j++) cin >> mat[i][j];

    for (int j = 1; j <= 19; j++) {
        for (int k = 1; k <= 19; k++) {
            int num = mat[j][k];
            if (num == 0) continue;

            if (!(j + 1 <= 19 && k - 1 >= 1 && mat[j + 1][k - 1] == num)) {
                startX = j; startY = k;
                find1(j, k, num, 1); if (win) return 0;
            }
            if (!(j - 1 >= 1 && mat[j - 1][k] == num)) {
                startX = j; startY = k;
                find2(j, k, num, 1); if (win) return 0;
            }
            if (!(k - 1 >= 1 && mat[j][k - 1] == num)) {
                startX = j; startY = k;
                find3(j, k, num, 1); if (win) return 0;
            }
            if (!(j - 1 >= 1 && k - 1 >= 1 && mat[j - 1][k - 1] == num)) {
                startX = j; startY = k;
                find4(j, k, num, 1); if (win) return 0;
            }
        }
    }
    if (!win) cout << 0;
    return 0;
}