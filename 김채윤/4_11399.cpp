#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr1[1000];
    int arr2[1000] ={0};
    int sum = 0;

    for (int i = 0; i < n; i++) 
        cin >> arr1[i];

    for (int k = 0; k < n; k++) {
        for (int m = k + 1; m < n; m++) {
            if (arr1[k] > arr1[m]) {
                int temp = arr1[k];
                arr1[k] = arr1[m];
                arr1[m] = temp;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int k = 0; k <= j; k++) {
            arr2[j] += arr1[k];
        }
        sum += arr2[j];
    }

    cout << sum;

    return 0;
}