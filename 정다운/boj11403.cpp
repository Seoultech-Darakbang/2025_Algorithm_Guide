#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int, int>> graph[n];

    if(n<1 || n>100) return 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int temp;
            cin>>temp;
            if(temp==1) {
                graph[i].emplace_back(make_pair(j, 1));
            }
            else {
                graph[i].emplace_back(make_pair(j, INF));
            }
        }
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(graph[i][k].second + graph[k][j].second < graph[i][j].second) {
                    graph[i][j].second = graph[i][k].second + graph[k][j].second;
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<graph[i].size(); j++) {
            if(graph[i][j].second!=INF) cout<<1<<' ';
            else cout<<0<<' ';
        }
        cout<<'\n';
    }
}