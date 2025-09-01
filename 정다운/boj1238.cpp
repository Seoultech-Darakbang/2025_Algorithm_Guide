#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10000000;
int n, m, x;
vector<int> nodes(1001, MAX);

void reset() {
    fill(nodes.begin(), nodes.end(), MAX);
}

void dijkstra(int start, vector<vector<int>> graph) {
    reset();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    nodes[start] = 0;
    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(int i=1; i<n+1; i++) {
            if(graph[node][i] == 0) continue;

            int nextWeight = graph[node][i];
            int nextNode = i;
            int newWeight = weight + nextWeight;

            if(nodes[nextNode] > newWeight) {
                nodes[nextNode] = newWeight;
                pq.push({newWeight, nextNode});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>x;

    vector<vector<int>> graph(n+1, vector<int>(n+1, MAX));
    vector<vector<int>> graphReversed(n+1, vector<int>(n+1, MAX));

    if(n<1 || n>1000 || m<1 || m>10000) return 0;

    for(int i=0; i<m; i++) {
        int start, end, t;
        cin>>start>>end>>t;
        graph[start][end] = t;
        graphReversed[end][start] = t;
    }

    vector<int> time(n+1, 0);
    dijkstra(x, graphReversed);
    for(int i=1; i<n+1; i++) {
        time[i] += nodes[i];
    }
    dijkstra(x, graph);
    for(int i=1; i<n+1; i++) {
        time[i] += nodes[i];
    }
    
    int max = 0;
    for(int i=1; i<n+1; i++) {
        if(max<time[i]) max = time[i];
    }
    cout<<max;
}