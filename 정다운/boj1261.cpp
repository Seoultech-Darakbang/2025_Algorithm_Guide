#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    if (n < 1 || m > 100)
        return 0;

    vector<vector<int>> maze(n, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            maze[j][i] = str[j] - '0';
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> weightofStart(n, vector<int>(m, -1));

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    pq.push({0, {0, 0}});
    weightofStart[0][0] = 0;

    while(!pq.empty()) {
        int weight = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx<0 || nx>n-1 || ny<0 || ny>m-1) continue;

            int nextWeight = maze[nx][ny];

            int newWeight = weight + nextWeight;
            
            if(weightofStart[nx][ny]==-1 || newWeight < weightofStart[nx][ny]) {
                weightofStart[nx][ny] = newWeight;
                pq.push({newWeight, {nx, ny}});
            }
        }
    }

    cout<<weightofStart[n-1][m-1];
}