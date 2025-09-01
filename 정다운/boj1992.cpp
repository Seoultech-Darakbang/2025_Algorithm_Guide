#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> m;
vector<string> result;

bool isSameColor(int x, int y, int size) {
    int color = m[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (color != m[i][j])
                return false;
        }
    }
    return true;
}

void divide(int x, int y, int size) {
    if (isSameColor(x, y, size)) {
        result.push_back(to_string(m[x][y]));
    } else {
        int half = size / 2;
        result.push_back("(");
        divide(x, y, half);
        divide(x, y + half, half);
        divide(x + half, y, half);
        divide(x + half, y + half, half);
        result.push_back(")");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    m.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            m[i][j] = line[j] - '0';
        }
    }

    divide(0, 0, n);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
}