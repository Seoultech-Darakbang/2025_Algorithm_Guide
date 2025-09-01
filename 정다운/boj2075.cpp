#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int temp;
    priority_queue<int, vector<int>, greater<int>> table;

    for(int i=0; i<n*n; i++) {
            cin>>temp;
            table.push(temp);
            if(table.size() > n) {
                table.pop();
            }
    }
    cout<<table.top()<<'\n';
}