#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char>> mat1(n + 2, vector<char>(n + 2));
    vector<vector<char>> mat2(n + 2, vector<char>(n + 2));
    vector<vector<int>> ans(n + 2, vector<int>(n + 2, 0));

    bool isFound = false;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            mat1[i][j] = s[j - 1];
            if (mat1[i][j] == '*') {
                ans[i - 1][j - 1]++;
                ans[i - 1][j]++;
                ans[i - 1][j + 1]++;
                ans[i][j - 1]++;
                ans[i][j + 1]++;
                ans[i + 1][j - 1]++;
                ans[i + 1][j]++;
                ans[i + 1][j + 1]++;
            }
        }
    }
    for (int j = 1; j <= n; j++) {
        string s;
        cin >> s;
        for (int k = 1; k <= n; k++) {
            mat2[j][k] = s[k - 1];
            if (mat2[j][k] == 'x' && mat1[j][k] == '*') {
                isFound = true;
            }
        }
    }

    if (isFound) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                if (mat1[k][i] == '*') cout << '*';
                else if (mat2[k][i] == 'x') cout << ans[k][i];
                else if (mat2[k][i] == '.') cout << '.';
            }
            cout << "\n";
        }
    }
    else {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                if (mat2[k][i] == 'x') cout << ans[k][i];
                else if (mat2[k][i] == '.') cout << '.';
            }
            cout << "\n";
        }
    }


    return 0;
}