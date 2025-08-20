#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> graph[1001];
bool visited[1001];

void reset()
{
    for (int i = 0; i < 1001; i++)
    {
        visited[i] = false;
    }
}

void dfs(int x)
{
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < graph[x].size(); i++)
    {
        int y = graph[x][i];
        if (!visited[y])
        {
            dfs(y);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << start << ' ';

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
                cout << y << ' ';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n+1; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    reset();
    cout << '\n';
    bfs(v);
}
