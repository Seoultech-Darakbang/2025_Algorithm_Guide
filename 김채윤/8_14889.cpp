#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e9;
int min1;

void comb(vector<vector<int>>& v, int start, int k, int N, vector<int>& pick) {
    if (k == 0) {
        int x = 0;
        int y = 0;
        vector<int> find(N + 1, 1);
        for (int l = 0; l < pick.size(); l++) {
            find[pick[l]] = 0;
            for (int i = l + 1; i < pick.size(); i++) {
                x += v[pick[l]][pick[i]];
            }
        }
        vector<int> n_pick;
        for (int j = 1; j <= N; j++)
            if (find[j] == 1) n_pick.push_back(j);

        for (int i = 0; i < n_pick.size(); i++) 
            for (int j = i + 1; j < n_pick.size(); j++) 
                y += v[n_pick[i]][n_pick[j]];

        if (abs(x - y) < min1) min1 = abs(x - y);

        return;
    }
    for (int i = start; i <= N - k + 1; i++) {
        pick.push_back(i);
        comb(v, i + 1, k - 1, N, pick);
        pick.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> v(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) cin >> v[i][j];
    
    for (int j = 1; j <= N; ++j)
        for (int i = 1; i < j; ++i)
            v[i][j] += v[j][i];

    min1 = INF;

    vector<int> pick;
    comb(v, 1, N / 2, N, pick);

    cout << min1;

    return 0;
}