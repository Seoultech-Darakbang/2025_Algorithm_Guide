#include <iostream>
#include <vector>
using namespace std;

int board[5][5];

// 빙고판의 숫자를 0으로 바꾸기
void change_to_zero(int x){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(board[i][j] == x){
                board[i][j] = 0;
                return;
            }
        }
    }
}

// 빙고 줄 세기
int count_bingo(){
    int count = 0;

    for(int i = 0; i < 5; i++){
        bool bingo = true;
        for(int j = 0; j < 5; j++)
            if(board[i][j] != 0)  bingo = false;

        if(bingo)  count++;
    }

    for(int i = 0; i < 5; i++){
        bool bingo = true;
        for(int j = 0; j < 5; j++)
            if(board[j][i] != 0)  bingo = false;
        
        if(bingo)  count++;
    }

    bool bingo = true;
    for(int i = 0; i < 5; i++)
        if(board[i][i] != 0)  bingo = false;
    if(bingo)  count++;

    bingo = true;
    for(int i = 0; i < 5; i++)
        if(board[i][4-i] != 0)  bingo = false;
    if(bingo)  count++;

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> board[i][j];

    for (int i = 1; i <= 25; i++) {
        int x; 
        cin >> x;
        change_to_zero(x);

        if (count_bingo() >= 3) {
            cout << i << "\n";
            break;
        }
    }
    
    return 0;
}
