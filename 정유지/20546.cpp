#include <iostream>
using namespace std;

int bnp(int* stock, int cash){
    int stockNum = 0;

    for(int i = 0; i < 14; i++){
        if(cash >= stock[i]){
            stockNum += cash /stock[i];
            cash %= stock[i];
        }
    }

    return cash + stockNum * stock[13];
}

int timing(int* stock, int cash){
    int up_count = 0, down_count = 0, stockNum = 0;

    for(int i = 1; i < 14; i++){
        if(stock[i-1] > stock[i]){
            up_count = 0;
            down_count++;
        }
        else if(stock[i-1] < stock[i]){
            up_count++;
            down_count = 0;
        }
        else{
            up_count = 0;
            down_count = 0;
        }

        if(up_count >= 3 && stockNum > 0){
            cash += stockNum * stock[i];
            stockNum = 0;
        }
        else if(down_count >= 3 && cash >= stock[i]){
            stockNum += cash / stock[i];
            cash %= stock[i];
        }
    }

    return cash + stockNum * stock[13];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int cash;
    int stock_price[14];

    cin >> cash;
    for(int i = 0; i < 14; i++)
        cin >> stock_price[i];

    int profit1 = bnp(stock_price, cash);
    int profit2 = timing(stock_price, cash);

    if(profit1 > profit2)
        cout << "BNP" << endl;
    else if(profit1 < profit2)
        cout << "TIMING" << endl;
    else
        cout << "SAMESAME" << endl; 

    return 0;
}
