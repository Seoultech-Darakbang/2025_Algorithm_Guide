#include <iostream>
#include <vector>
using namespace std;

long long n, b;
typedef vector<vector<int>> matrix;

matrix multiply(const matrix &a, const matrix &b) {
    matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j] % 1000;
                result[i][j] %= 1000;
            }
        }
    }
    return result;
}

matrix power(matrix a, long long exp) {
    if (exp == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] %= 1000;
            }
        }
        return a;
    }
    matrix half = power(a, exp / 2);      // 지수가 1이 될 떄 까지 재귀 반복
    matrix result = multiply(half, half); //

    if (exp % 2 == 1) // 지수가 홀수면 a를 한 번 더 곱셈
        result = multiply(result, a);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> b;
    matrix a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    matrix ans = power(a, b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}