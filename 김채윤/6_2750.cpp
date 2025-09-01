#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int list[1001];

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            if (list[j] > list[k]) {
                int temp = list[j];
                list[j] = list[k];
                list[k] = temp;
            }
        }
    }
    for (int k = 0; k < n; k++) 
        cout << list[k] << endl;

    return 0;
}