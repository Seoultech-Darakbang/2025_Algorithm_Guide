#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[50];
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    vector<int> v;
    int visited[50] = {0};
    int sum = 0;

    for (int j = 0; j < N - 1; j++) {
        if (!visited[j] && arr[j] < 0 && arr[j + 1] <= 0) {
            sum += arr[j] * arr[j + 1];
            visited[j] = visited[j + 1] = 1;
        }
    }
    for (int j = 0; j < N; j++) {
        if (!visited[j] && arr[j] < 0) {
            sum += arr[j];
            visited[j] = 1;
        }
    }

    for (int j = N - 1; j > 0; j--) {
        if (!visited[j] && arr[j] > 1 && arr[j - 1] > 1) {
            sum += arr[j] * arr[j - 1];
            visited[j] = visited[j - 1] = 1;
        }
    }
    for (int j = 0; j < N; j++) {
        if (!visited[j]) sum += arr[j];
    }

    cout << sum;
    return 0;
}