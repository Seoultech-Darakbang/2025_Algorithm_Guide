#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> bus[n+1];

    if(n<1 || n>1000 || m<1 || m>100000) return 0;

    for(int i=0; i<m; i++) {
        int start, end, cost;
        cin>>start>>end>>cost;
        bus[start].emplace_back(make_pair(end, cost));
    }
    int start, end;
    cin>>start>>end;

    priority_queue<pair<int, int>> pq;
    vector<int> costofStart(n+1, -1);

    pq.push({start, 0});
    costofStart[start] = 0;

    while(!pq.empty()) {
        int node = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if(costofStart[node] < cost) continue;

        for(auto now : bus[node]) {
            int nextNode = now.first;
            int nextCost = now.second;

            if(costofStart[nextNode]==-1 || costofStart[nextNode] > cost + nextCost) {
                costofStart[nextNode] = cost + nextCost;
                pq.push({nextNode, cost + nextCost});
            }
        }
    }
    cout<<costofStart[end];
}