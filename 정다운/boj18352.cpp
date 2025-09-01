#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, k, x;

    cin>>n>>m>>k>>x;

    vector<int> graph[n+1];
    vector<int> nodes(n+1, -1);

    for(int i=0; i<m; i++) {
        int temp1, temp2;
        cin>>temp1>>temp2;
        graph[temp1].push_back(temp2);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(x);
    nodes[x] = 0;

    while(!pq.empty()) {
        int j = pq.top();
        pq.pop();

        for(int i=0; i<graph[j].size(); i++) {
            int y = graph[j][i];
            if(nodes[y]==-1 || nodes[j] + 1 < nodes[y]) {
                nodes[y] = nodes[j] + 1;
                pq.push(y);
            }
        }
    }

    bool found = false;
    for(int i=1; i<nodes.size(); i++) {
        if(nodes[i] == k) {
            cout<<i<<'\n';
            found = true;
        }
    }
    
    if(!found) {
        cout<<"-1";
    }
}