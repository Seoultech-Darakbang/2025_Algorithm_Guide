#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[1000001];
vector<int> graph[1000001];

void bfs(int start, int end)
{
    queue<int> q;
    int count = 0;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int x = q.front();
        if(x==end) {
            cout<<count;
            return;
        }
        q.pop();
        for (int i = 0; i < graph[x].size(); i++)
        {
            int y;
            if(end>x) {
                y = graph[x][0];
            }
            else {
                if(graph[x].size()>1) {
                    y = graph[x][1];
                }
                else {
                    y = graph[x][0];
                }
            }
            if (!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }
        }
        count++;
    }
    cout << "use the stairs";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int f, s, g, u, d;
    cin>>f>>s>>g>>u>>d;

    if(s<1 || g > f || f > 1000000 || u <0 || d >1000000) {
        return 0;
    }

    for(int i=1; i<=f; i++) {
        if(i+u <= f) {
            graph[i].push_back(i+u);
        }
        if(i-d >= 1) { 
            graph[i].push_back(i-d);
        }
    }
    
    bfs(s, g);
}