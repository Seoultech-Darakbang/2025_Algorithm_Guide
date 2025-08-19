#include <iostream>
using namespace std;

long long z(int N, long long r, long long c) {
    long long side = 1;
    for (int i = 0; i < N; ++i) side *= 2; 

    long long ans = 0;
    while (side > 1) {
        long long half = side / 2;

        if (r < half && c < half) {
        } else if (r < half && c >= half) {
            ans += half * half;
            c -= half;
        } else if (r >= half && c < half) {
            ans += 2 * half * half;
            r -= half;
        } else {
            ans += 3 * half * half;
            r -= half;
            c -= half;
        }
        side = half;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; long long r, c;
    cin >> N >> r >> c;
    cout << z(N, r, c) << '\n';
    return 0;
}