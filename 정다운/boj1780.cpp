#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int minusOne = 0;
int zero = 0;
int plusOne = 0;

void slice(int n, const vector<vector<int>> &paper, int x, int y) {
    int first = paper[x][y];
    bool isSame = true;

    for(int i=x; i<x+n; ++i) { //종이가 같은 수인지 확인
        for(int j=y; j<y+n; ++j) {
            if(paper[i][j] != first) {
                isSame = false;
                break;
            }
        }
        if(!isSame) break;
    }

    if(isSame) { //같은 수라면 해당하는 수++, 아니면 코드 진행
        switch (first) {
        case -1: 
            minusOne++;
            return;
        case 0:
            zero++;
            return;
        case 1:
            plusOne++;
            return;
        }
    }

    int newSize = n/3;
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            slice(newSize, paper, x+i*newSize, y+j*newSize);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    
    if(n<1 || n>pow(3, 7)) return 0;

    vector<vector<int>> paper(n, vector<int>(n, 0));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>paper[i][j];
        }
    }

    slice(n, paper, 0, 0);

    cout<<minusOne<<'\n';
    cout<<zero<<'\n';
    cout<<plusOne<<'\n';
}