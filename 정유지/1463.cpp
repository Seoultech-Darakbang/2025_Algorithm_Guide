#include <iostream>
using namespace std;

int DP[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        // n을 1로 만들기 위해 필요한 최소 횟수 = (n-1을 1로 만들기 위한 최소횟수 + 1)
        DP[i] = DP[i-1] + 1;

        if(i % 2 == 0)
            DP[i] = min(DP[i], DP[i/2] + 1);
        
        if(i % 3 == 0)
            DP[i] = min(DP[i], DP[i/3] + 1);
    }

    cout << DP[n] << endl;
    
    return 0;
}
