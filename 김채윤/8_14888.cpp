#include <iostream>
using namespace std;

int N;
long long A[12];
long long mxVal, mnVal;

void dfs(int idx, long long cur, int p, int m, int t, int d) {
    if (idx == N - 1) {
        if (cur > mxVal) mxVal = cur;
        if (cur < mnVal) mnVal = cur;
        return;
    }
    long long nextNum = A[idx + 1];
    if (p > 0) dfs(idx + 1, cur + nextNum, p - 1, m, t, d);
    if (m > 0) dfs(idx + 1, cur - nextNum, p, m - 1, t, d);
    if (t > 0) dfs(idx + 1, cur * nextNum, p, m, t - 1, d);
    if (d > 0 && nextNum != 0) dfs(idx + 1, cur / nextNum, p, m, t, d - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    int p, m, t, d;
    cin >> p >> m >> t >> d;

    mxVal = -(1LL << 60);
    mnVal =  (1LL << 60);

    dfs(0, A[0], p, m, t, d);

    cout << mxVal << "\n" << mnVal << "\n";
    return 0;
}