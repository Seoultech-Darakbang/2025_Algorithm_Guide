#include <iostream>
using namespace std;

bool group_word(string word){
    bool alp[26] = {false};
    char prev = '\0';

    for(char current : word){
        if(current != prev){
            if(alp[current-'a'])  return false;
            alp[current-'a'] = true;
        }
        prev = current;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, cnt = 0; 
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(group_word(s))  cnt++;
    }

    cout << cnt << endl;

    return 0;
}
