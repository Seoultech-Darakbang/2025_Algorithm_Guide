#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<bool>> map;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void bfs() {
    vector<vector<int>> time(n, vector<int>(m, -1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    time[0][0] = 1;
    visited[0][0] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=m) {
                continue;
            }
            if(nx==n-1 && ny==m-1) {
                cout<<time[x][y] + 1;
                return;
            }
            if(map[nx][ny]==true && !visited[nx][ny]) {
                q.push({nx, ny});
                time[nx][ny] = time[x][y] + 1;
                visited[nx][ny] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    if(n<2 || m>100) {
        return 0;
    }

    for(int i=0; i<n; i++) {
        string str;
        cin>>str;
        vector<bool> temp;
        for(int j=0; j<m; j++) {
            if(str[j] == '1') {
                temp.push_back(true);
            }
            else {
                temp.push_back(false);
            }
        }
        map.push_back(temp);
    }

    q.push({0, 0});
    bfs();
}