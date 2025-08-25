#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);

    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    for(int num : numbers)
        cout << num << "\n";
    
    return 0;
}
