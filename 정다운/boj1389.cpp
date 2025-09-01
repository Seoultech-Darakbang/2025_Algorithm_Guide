#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> graph[n];

    if(n<2 || n>100 || m<1 || m>5000) return 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            graph[i].emplace_back(make_pair(j, INF));
        }
    }

    for(int i=0; i<m; i++) {
        int temp1, temp2;
        cin>>temp1>>temp2;
        graph[temp1-1][temp2-1] = make_pair(temp2-1, 1);
        graph[temp2-1][temp1-1] = make_pair(temp1-1, 1);
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

    vector<pair<int, int>> result;
    
    for(int i=0; i<n; i++) {
        int bacon = 0;
        for(int j=0; j<graph[i].size(); j++) {
            bacon += graph[i][j].second;
        }
        result.emplace_back(make_pair(i, bacon));
    }
    
    sort(result.begin(), result.end(), compare);
    cout<<result[0].first+1;
}