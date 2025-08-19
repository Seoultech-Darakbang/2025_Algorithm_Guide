#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int money;
    cin >> money;

    int arr[15] = {0};
    for (int idx = 1; idx <= 14; idx++) cin >> arr[idx];

    int money_j = money;
    int money_s = money;

    int have_j = 0;
    int have_s = 0;

    for (int i = 1; i <= 14; i++) {
        if (money_j >= arr[i]) {
            int n = (money_j / arr[i]);
            money_j -= n * arr[i];
            have_j += n;
        }
    }
    for (int j = 4; j <= 14; j++) {
        if (arr[j - 3] < arr[j - 2] && arr[j - 2] < arr[j - 1] && arr[j - 1] < arr[j]) {
            money_s += arr[j] * have_s;
        }
        else if (arr[j - 3] > arr[j - 2] && arr[j - 2] > arr[j - 1] && arr[j - 1] > arr[j]) {
            if (money_s >= arr[j]) {
                int m = money_s / arr[j];
                money_s -= m * arr[j];
                have_s += m;
            }
        }
    }

    money_j += arr[14] * have_j;
    money_s += arr[14] * have_s;

    if (money_j > money_s) cout << "BNP";
    else if (money_j < money_s) cout << "TIMING";
    else cout << "SAMESAME";

    return 0;
}