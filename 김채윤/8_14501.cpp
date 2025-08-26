#include <iostream>
#include <vector>
using namespace std;

int N;

int find(vector<pair<int, int>>& v, vector<int>& vec, int day) {
    if (day > N) return 0;

    int sum = find(v, vec, day + 1);

    if (day + v[day].first <= N + 1)
        sum = max(sum, v[day].second + find(v, vec, day + v[day].first));

    return sum;
}

int main() {
    cin >> N;

    vector<pair<int, int>> v(N + 1);
    vector<int> vec(N + 1, 0);

    for (int i = 1; i <= N; i++) cin >> v[i].first >> v[i].second;

    cout << find(v, vec, 1);

    return 0;
}
//