#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> vec(n);
    unordered_set<int> seen;
    
    for(int i=0; i<n; i++) {
        cin>>vec[i];
    }

    int x;
    cin>>x;
    
    int count = 0;
    unordered_set<int> used;

    for(int num : vec) { // for(declaration : container) 컨테이너를 순회하는 범위 기반 for 루프 구문
        int  complement = x - num;
        if(seen.count(complement) > 0 && !used.count(num)) {
            count++;
            used.insert(num);
            used.insert(complement);
        }
        seen.insert(num);
    }

    cout<<count<<"\n";

    return 0;
}