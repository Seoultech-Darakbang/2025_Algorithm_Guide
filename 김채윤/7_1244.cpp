#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int s[101];
    for (int idx = 1; idx <= n; idx++) cin >> s[idx];

    int sn;
    cin >> sn;

    for (int i = 0; i < sn; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            for (int j = y; j <= n; j += y) {
                if (s[j] == 1) s[j] = 0;
                else if (s[j] == 0) s[j] = 1;
            }
        }
        else if (x == 2) {
                if (s[y] == 1) s[y] = 0;
                else if (s[y] == 0) s[y] = 1;
                int d = 1;
                while (y - d >= 1 && y + d <= n && s[y - d] == s[y + d]) {
                    if (s[y - d] == 1) s[y - d] = 0;
                    else if (s[y - d] == 0) s[y - d] = 1;

                    if (s[y + d] == 1) s[y + d] = 0;
                    else if (s[y + d] == 0) s[y + d] = 1;

                    d++;
                }
        }
    }
    for (int j = 1; j <= n; j++) {
        cout << s[j] << " ";
        if (j % 20 == 0) cout << "\n";
    }
    
    return 0;
}