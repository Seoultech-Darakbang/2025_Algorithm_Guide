#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Steelstick
{
    int begin, end;
    int razor;
    int getNumberofRazor() {
        return razor;
    }
    int numberOfParts(int n) {
        return n+1;
    }
};


int main() {
    string str;
    stack<int> s;
    int count = 0;
    cin>>str;

    for(int i=0; i<str.size(); i++) {
        if(str[i]=='(' && str[i+1]==')') {
            count += s.size();
            i++;
        }
        else if(str[i]=='(') {
            s.push(i);
        }
        else if(str[i]==')') {
            count++;
            s.pop();
        }
    }
    cout<<count<<'\n';
}