#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[626];
bool visited[626];
vector<int> apt;
int countApt = 0;

void bfs(int start)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);
    apt.push_back(1);
    countApt++;

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
                apt[countApt-1]++;
            }
        }
    }
}

void isside(int n1, int n2, int m)
{
    if (n1 - 1 == n2 || n1 + 1 == n2)
    {
        if (!(((n1 + 1) % m == 0 && n2 % m == 0) || (n1 % m == 0 && (n2 + 1) % m == 0)))
        {
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
    }

    if (n1 - m == n2 || n1 + m == n2)
    {
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<string> str;
    vector<int> map;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if(str[j] == '1') {
                map.push_back(i*n+j);
            }
        }
    }

    for (int i = 0; i < map.size(); i++)
        {
            for (int z = 0; z < map.size() - 1; z++)
            {
                isside(map[i], map[z], n);
            }
        }

    for (int i = 0; i < map.size(); i++)
    {
        if (!visited[map[i]])
        {
            bfs(map[i]);
        }
    }
    cout << countApt << '\n';
    sort(apt.begin(), apt.end());
    for(int i=0; i<apt.size(); i++) {
        cout<<apt[i]<<'\n';
    }
}