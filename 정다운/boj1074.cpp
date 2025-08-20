#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int result = 0;

void divide(int x, int y, int size) {
    if (size == 1) {
        if (x == r && y == c) {
            cout << result;
            return;
        } else {
            result++;
            return;
        }
    }
    int half = size / 2;

    // x, y가 어느 사분면에 속하는지에 따라 재귀 수행
    if (r < x + half && c < y + half) {
        divide(x, y, half);
    } else if (r < x + half && c >= y + half) {
        result += half * half;
        divide(x, y + half, half);
    } else if (r >= x + half && c < y + half) {
        result += 2 * half * half;
        divide(x + half, y, half);
    } else if (r >= x + half && c >= y + half) {
        result += 3 * half * half;
        divide(x + half, y + half, half);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> c;
    int size = pow(2, n);

    divide(0, 0, size);
    return 0;
}