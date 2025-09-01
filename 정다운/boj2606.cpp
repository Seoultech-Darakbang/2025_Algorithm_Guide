#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];
vector<int> polluted;

void bfs(int start)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);
    polluted.push_back(start);

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
                polluted.push_back(y);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    
    cin>>n>>k;

    for(int i=0; i<k; i++) {
        int n1, n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    for(int i=0; i<n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    bfs(1);
    cout<<polluted.size()-1;
}
