#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 1;
    int n = 1;

    while(n!=0)
    {
        cin >> n;
        if(n<2 || n>125) return 0;

        vector<vector<int>> cave(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int c;
                cin>>c;
                cave[i][j] = c;
            }
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> weightofStart(n, vector<int>(n, -1));

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        pq.push({cave[0][0], {0, 0}});
        weightofStart[0][0] = 5;

        while (!pq.empty())
        {
            int weight = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1)
                    continue;

                int nextWeight = cave[nx][ny];

                int newWeight = weight + nextWeight;

                if (weightofStart[nx][ny] == -1 || newWeight < weightofStart[nx][ny])
                {
                    weightofStart[nx][ny] = newWeight;
                    pq.push({newWeight, {nx, ny}});
                }
            }
        }
        cout<<"Problem "<<count++<<": "<<weightofStart[n-1][n-1]<<'\n';
    }
}