#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int stairs[301], scores[301];

    for(int i = 1; i <= n; i++){
        cin >> stairs[i];
    }

    scores[1] = stairs[1];
    scores[2] = stairs[1] + stairs[2];;
    scores[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
    
    for(int i = 4; i <= n; i++){
        int s1 = scores[i-2] + stairs[i];
        int s2 = scores[i-3] + stairs[i-1] + stairs[i];

        scores[i] = max(s1, s2);
    }
    
    cout << scores[n] << endl;

    return 0;
}
