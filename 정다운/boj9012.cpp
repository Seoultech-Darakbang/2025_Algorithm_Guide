#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isVPS(string data) {
    stack<char> stack;
    for(char i : data) {
        if(i == '(') {
            stack.push(i);
        }
        else if(i ==')') {
            if(stack.empty()) {
                return false;
            }
            else if(stack.top() == '(') {
                stack.pop();
            }
        }
        else {
            return false;
        }
    }
    return stack.empty();
}

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        string str;
        cin>>str;
        if(isVPS(str)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}