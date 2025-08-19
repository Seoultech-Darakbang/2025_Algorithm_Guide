#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    priority_queue<tuple<int,int,int,int>> pq;

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pq.emplace(b, c, d, a); 
    }

    if (pq.empty()) { cout << -1; return 0; }

    int x = get<3>(pq.top());
    int a = get<0>(pq.top()); 
    int b = get<1>(pq.top()); 
    int c = get<2>(pq.top());
    pq.pop();

    int count1 = 1; 
    int count2 = 1; 

    if (x == K) { cout << count1; return 0; }

    while (!pq.empty()) {
        int a2 = get<0>(pq.top()); 
        int b2 = get<1>(pq.top());
        int c2 = get<2>(pq.top()); 
        int x2 = get<3>(pq.top()); 

        if (a == a2 && b == b2 && c == c2) {
            count2++;
        } 
        else {
            count1 += count2;
            count2 = 1;
            a = a2; b = b2; c = c2; 
        }

        pq.pop();
        x = x2;

        if (x == K) { cout << count1; return 0; }
    }

    cout << -1;
    return 0;
}