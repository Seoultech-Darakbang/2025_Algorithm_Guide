#include <iostream>
#include <vector>
using namespace std;

int main() {
    string cipher;
    cin >> cipher;
    int length = cipher.length();
    
    if (length == 0 || cipher[0] == '0') {
        cout << 0;
        return 0;
    }

    vector<int> dp(length + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= length; i++) {
        int a = cipher[i - 2] - '0';
        int b = cipher[i - 1] - '0';
        int num = a * 10 + b;

        if (b != 0 && num >= 10 && num <= 26) 
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
        else if (b != 0)
            dp[i] = dp[i - 1];
        else if (num == 10 || num == 20) 
            dp[i] = dp[i - 2];
        else {
            cout << 0;
            return 0;
        }
    }

    cout << dp[length] % 1000000;

    return 0;
}