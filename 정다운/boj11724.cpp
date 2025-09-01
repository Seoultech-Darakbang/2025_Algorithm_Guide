#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
int n, m, countBfs = 0;

void bfs(int start)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < graph[x].size(); i++)
        {
            int y = graph[x][i];
            if (!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            bfs(i);
            countBfs++;
        }
    }
    cout<<countBfs;
}