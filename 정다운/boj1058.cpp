#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1000000
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int, int>> graph[n];

    if(n>50) return 0;

    for(int i=0; i<n; i++) {
        string str;
        cin>>str;
        for(int j=0; j<str.size(); j++) {
            if(str[j] == 'Y') {
                if(find(graph[i].begin(), graph[i].end(), make_pair(j, 1)) == graph[i].end()) {
                    graph[i].emplace_back(j, 1);
                }
                if(find(graph[j].begin(), graph[j].end(), make_pair(i, 1)) == graph[j].end()) {
                    graph[j].emplace_back(i, 1);
                }
            }
            else {
                if(find(graph[i].begin(), graph[i].end(), make_pair(j, INF)) == graph[i].end()) {
                    graph[i].emplace_back(j, INF);
                }
                if(find(graph[j].begin(), graph[j].end(), make_pair(i, INF)) == graph[j].end()) {
                    graph[j].emplace_back(i, INF);
                }
            }
        }
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(graph[i][k].second + graph[k][j].second < graph[i][j].second && graph[i][k].second + graph[k][j].second <= 2) {
                    graph[i][j].second = graph[i][k].second + graph[k][j].second;
                }
            }
        }
    }

    int friends[n];
    fill(friends, &friends[n], 0);
    for(int i=0; i<n; i++) {
        for(int j=0; j<graph[i].size(); j++) {
            if(graph[i][j].second <= 2) {
                friends[i]++;
            }
        }
    }

    int result = 0;
    for(int i=0; i<n; i++) {
        if(friends[i] > result) result = friends[i];
    }
    cout<<result;
}