#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;


    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int arr['z' - 'a' + 1] = {0};
        int m = s[0] - 'a';
        arr[m] = 1;

        bool isGroup = true;

        for (int j = 1; j < s.length(); j++) {
            int a = s[j] - 'a';
            if (arr[a] == 0) {
                arr[a] = 1;
                m = a;
            }
            else if (m == a) {}
            else isGroup = false;
        }
        if (isGroup == true) sum++;
    }
    
    cout << sum;
    
    return 0;
}