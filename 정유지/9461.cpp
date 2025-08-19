#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    long triangle[101];
    triangle[1] = triangle[2] = triangle[3] = 1;
    triangle[4] = triangle[5] = 2;
    
    for(int j = 6; j <= 100; j++)
        triangle[j] = triangle[j-5] + triangle[j-1];

    for(int i = 0; i < t; i++){
        int x;
        cin >> x;
        cout << triangle[x] << endl;
    }


    return 0;
}
