#include <iostream>
using namespace std;

const int MAX = 1000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int people[MAX];
    for(int i = 0; i < n; i++)
        cin >> people[i];

    // 선택정렬
    for(int i = 0; i < n - 1; i++){
        int min = people[i];
        int min_index = i;

        for(int j = i + 1; j < n; j++){
            if(people[j] < min){
                min = people[j];
                min_index = j;
            }  
        }
        int tmp = people[i];
        people[i] = min;
        people[min_index] = tmp;
    }

    // 최소 시간 구하기
    int total = 0;
    for(int i = 0; i < n; i++)
        total += people[i] * (n-i);

    cout << total << endl;    

    return 0;
}
