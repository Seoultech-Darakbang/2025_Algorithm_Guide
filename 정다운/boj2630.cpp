#include <iostream>
#include <vector>
using namespace std;

int n;
int result[2] = {0, 0};
typedef vector<vector<int>> matrix;
matrix m;

// 시작 좌표, size를 인자로 받아 해당 행렬이 같은 색으로 이루어졌는지 검사
bool isSameColor(int x, int y, int size) {
    int color = m[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (m[i][j] != color)
                return false;
        }
    }
    return true;
}

// 행렬이 같은 색이면 결과값 ++, 아니면 재귀적으로 4분할 수행
void divide(int x, int y, int size) {
    if (isSameColor(x, y, size)) {
        result[m[x][y]]++;
    } else {
        int half = size / 2;
        divide(x, y, half);
        divide(x, y + half, half);
        divide(x + half, y, half);
        divide(x + half, y + half, half);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    m.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    divide(0, 0, n);
    cout << result[0] << "\n" << result[1];
}