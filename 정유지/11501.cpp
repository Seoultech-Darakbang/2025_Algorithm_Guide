#include <iostream>
using namespace std;

const int MAX = 1000000;

void stock(int p[], int size){
    long long max = 0, profit = 0;

    for(int i = size - 1; i >= 0; i--){
        if(max <= p[i])  max = p[i];  // 최고가보다 현재가가 크면 최고가 갱신
        else  profit += (max - p[i]);  // 작은 경우 이익 증가
    }

    cout << profit << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int prices[MAX];

        for(int i = 0; i < n; i++)
            cin >> prices[i];

        stock(prices, n);
    }

    return 0;
}
