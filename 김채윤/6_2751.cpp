#include <iostream>
#include <algorithm>
using namespace std;

static const int MAXN = 1000000;
int arr[MAXN];  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}