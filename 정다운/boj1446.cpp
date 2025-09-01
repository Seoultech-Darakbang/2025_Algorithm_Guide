#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin>>n>>d;

    vector<pair<int, int>> graph[d+1];
    vector<int> nodes(d+1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    if(n>12 || d>10000) {
        return 0;
    }

    for(int i=0; i<d; i++) {
        graph[i].emplace_back(i+1, 1);
    }

    for(int i=0; i<n; i++) {
        int temp1, temp2, temp3;
        cin>>temp1>>temp2>>temp3;
        if(temp2 > d) {
            continue;
        }
        graph[temp1].emplace_back(temp2, temp3);
    }

    pq.push({0, 0});
    nodes[0] = 0;

    while(!pq.empty()) {
        int node = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        for(auto now : graph[node]) {
            int nextNode = now.first;
            int nextWeight = now.second;

            if(nodes[nextNode]==-1 || nodes[nextNode] > weight + nextWeight) {
                nodes[nextNode] = weight + nextWeight;
                pq.push({nextNode, weight + nextWeight});
            }
        }
    }
    cout<<nodes[d];
}