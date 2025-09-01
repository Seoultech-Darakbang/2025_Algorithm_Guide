#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100002

vector<int> graph[MAX];
vector<bool> visited(MAX, false);
queue<int> q;

int n, k, count = 0;

void bfs() {
    int time[MAX];
    fill(time, time+MAX, -1);
    q.push(n);
    time[n] = 0;
    while(!q.empty()) {
        int x = q.front();
        int dx[] = {x-1, x+1, x*-2, x*2};

        if(x==k) {
            cout<<time[x];
            return ;
        }

        for(int dir=0; dir<4; dir++) {
            int nx = dx[dir];
            if(nx<0 || nx>100000) continue;
            if(time[nx] >= 0 ) continue;
            time[nx] = time[x] + 1;
            q.push(nx);
        }
        q.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    if(n<0 || n>100000 || k<0 || k>100000) {
        return 0;
    }

    bfs();
}