#include <iostream>
#include <algorithm>
using namespace std;

bool canPlace(long long dist, long long C, long long arr[], long long l) {
    int placed = 1;
    long long last = arr[0];

    for (long long i = 1; i < l; i++) {
        if (arr[i] - last >= dist) {
            placed++;
            last = arr[i];
        }
    }
    return placed >= C;
}

long long binary_search(long long low, long long high, long long n, long long arr[], long long l) {
    long long max = 0;

    while (low <= high) {
        long long mid = (high + low) / 2;

        if (canPlace(mid, n, arr, l)) {
            max = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return max;
}

int main() {
    int N, C;
    cin >> N >> C;
    long long arr[200000];

    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    long long low = 1;
    long long high = arr[N - 1] - arr[0];

    cout << binary_search(low, high, C, arr, N);
    return 0;
}