#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100

vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
vector<vector<int>> map(MAX, vector<int>(MAX));
int n;
int safetyArea;
queue<pair<int, int>> q;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int height) {
    while(!q.empty()) {
        pair<int, int> x = q.front();
        visited[x.first][x.second] = true;
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = x.first + dx[dir];
            int ny = x.second + dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=n) {
                continue;
            }
            if(map[nx][ny]<=height || visited[nx][ny] == 1) {
                continue;
            }
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

void reset() {
    safetyArea = 0;
    for(int x=0; x<n; x++) {
        fill(visited[x].begin(), visited[x].end(), false);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int height = 0, result = 0;
    cin>>n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
            if(height < map[i][j]) height = map[i][j];
        }
    }

    while(height >= 0) {
        for(int x=0; x<n; x++) {
            for(int y=0; y<n; y++) {
                if(map[x][y] > height && !visited[x][y]) {
                    q.push({x, y});
                    bfs(height);
                    safetyArea++;
                }
            }
        }
        if(result < safetyArea) {
        result = safetyArea;
        }
        reset();
        height--;
    }
    cout<<result;
}