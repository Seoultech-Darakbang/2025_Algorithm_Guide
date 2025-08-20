#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100000000;
int n, e;

vector<vector<int>> graph(801, vector<int>(801, 0));
vector<int> nodes(801, MAX);

void reset() {
    fill(nodes.begin(), nodes.end(), MAX);
}

void dajik(int start) {
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

    cin>>n>>e;

    if(n>800 || n<2 || e>200000 || e<0) return 0;

    for(int i=0; i<e; i++) {
        int temp1, temp2, temp3;
        cin>>temp1>>temp2>>temp3;
        if(temp3>1000) return 0;
        graph[temp1][temp2] = temp3;
        graph[temp2][temp1] = temp3;
    }

    int v1, v2;
    cin>>v1>>v2;

    int distance1 = 0, distance2 = 0;

    dajik(1);
    distance1 += nodes[v1];
    distance2 += nodes[v2];
    reset();

    dajik(v1);
    distance1 += nodes[v2];
    distance2 += nodes[n];
    
    reset();

    dajik(v2);
    distance1 += nodes[n];
    distance2 += nodes[v1];
    

    for(int i=1; i<n+1; i++) {
        if(nodes[i] == MAX) {
            cout<<-1;
            return 0;
        }
    }
    cout<<min(distance1, distance2);
}