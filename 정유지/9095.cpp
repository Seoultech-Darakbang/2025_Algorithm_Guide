#include <iostream>
using namespace std;

int DP[11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    DP[1] = 1, DP[2] = 2, DP[3] = 4;
    for(int i = 4; i <= 11; i++){
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cout << DP[x] << endl;
    }
    
    return 0;
}
