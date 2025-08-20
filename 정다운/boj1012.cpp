#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
좌표 x, y를 가로 * y + x 를 통해 정수로 나타내고 정수끼리 양 옆으로 인접하면, 즉 좌표가 1 만큼 차이가 나거나(양 끝에서는 1만큼 차이가 나도 인접이 아님)위 아래로 인접하면, 즉 좌표가 가로만큼 차이가 나면 그래프에 서로 추가하고 bfs를 통해 연결되있다고 찾아낸 정수를 리스트에서 삭제, 남아 있는 정수를 bfs 돌리고 삭제를 반복하며 count를 세어 나가 몇 번 bfs를 반복했는지 센다.
*/

vector<int> graph[2501];
bool visited[2501];
vector<int> done;
int countBfs = 0;

void bfs(int start)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);
    done.push_back(start);

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
                done.push_back(y);
            }
        }
    }
    countBfs++;
}

void reset()
{
    for (int i = 0; i < 2501; i++)
    {
        graph[i].clear();
        visited[i] = false;
    }
    countBfs = 0;
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

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        reset();
        int m, n, k;
        cin >> m >> n >> k;

        vector<int> kmap;
        for (int j = 0; j < k; j++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            kmap.push_back(n2 * m + n1);
        }

        for (int j = 0; j < kmap.size(); j++)
        {
            for (int z = 0; z < kmap.size() - 1; z++)
            {
                isside(kmap[j], kmap[z], m);
            }
        }
        sort(kmap.begin(), kmap.end());
        for (int j = 0; j < 2501; j++)
        {
            sort(graph[i].begin(), graph[i].end());
        }
        while (kmap.size() != 0)
        {
            bfs(kmap.front());

            while (done.size() != 0)
            {
                kmap.erase(find(kmap.begin(), kmap.end(), done.front()));
                done.erase(done.begin());
            }
        }
        cout << countBfs << '\n';
    }
}