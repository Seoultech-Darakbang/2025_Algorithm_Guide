#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;
    vector<pair<int, int>> graph[v+1];

    if(v<1 || v>20000 || e<1 || e>300000) return 0;

    int start;
    cin>>start;

    for(int i=0; i<e; i++) {
        int temp1, temp2, temp3;
        cin>>temp1>>temp2>>temp3;
        graph[temp1].emplace_back(make_pair(temp3, temp2));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> weightofStart(v+1, -1);

    pq.push({0, start});
    weightofStart[start] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if(weightofStart[node] < weight) continue;

        for(auto now : graph[node]) {
            int nextNode = now.second;
            int nextWeight = now.first;

            if(weightofStart[nextNode]==-1 || weightofStart[nextNode] > weight + nextWeight) {
                weightofStart[nextNode] = weight + nextWeight;
                pq.push({weight + nextWeight, nextNode});
            }
        }
    }

    for(int i=1; i<v+1; i++) {
        if(weightofStart[i] == -1) cout<<"INF"<<'\n';
        else cout<<weightofStart[i]<<'\n';
    }
}