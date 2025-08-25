#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    int B, C;
    cin >> B >> C;

    long long count = 0;
    count = N;
    for (int j = 0; j < N; j++) {
        if (v[j] - B > 0) {
            count = count + (v[j] - B) / C;
            if ((v[j] - B) % C != 0) count++;
        }
    }

    cout << count;

    return 0;
}