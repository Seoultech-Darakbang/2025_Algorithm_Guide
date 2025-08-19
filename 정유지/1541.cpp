#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 문자열을 특정 연산자를 기준으로 분할
vector<string> split(string& s, char op){
    vector<string> part;

    int start_index = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == op){
            part.push_back(s.substr(start_index, i - start_index));
            start_index = i+1;
        }
    }

    part.push_back(s.substr(start_index));  // 마지막 부분 push
    return part;
}

// 문자열을 숫자로 변환
int makeNumber(string& s){
    int num = 0;
    for(char c : s)
        num = num * 10 + (c - '0');

    return num;
}


// 덧셈을 포함하는 문자열 계산
int sum_plus_part(string& s){
    vector<string> plus_part = split(s, '+');
    int sum = 0;

    for(string& p : plus_part)
        sum += makeNumber(p);

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    vector<string> part = split(s, '-');

    int answer = sum_plus_part(part[0]);
    
    for(int i = 1; i < part.size(); i++)
        answer -= sum_plus_part(part[i]);
    
    cout << answer << endl;

    return 0;
}
