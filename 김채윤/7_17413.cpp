#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int start = -1, end = -1;
    stack<char> st;
    bool isTag = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '<') {
            if (!st.empty()) {
                end = i - 1;
                for (int j = start; j <= end; j++) {
                    s[j] = st.top();
                    st.pop();
                }
                start = end = -1;
            }
            isTag = true;
        }
        else if (s[i] == '>') {
            isTag = false;
        }
        else if (s[i] == ' ') {
            if (!st.empty()) {
                end = i - 1;
                for (int j = start; j <= end; j++) {
                    s[j] = st.top();
                    st.pop();
                }
                start = end = -1;
            }
        }
        else {
            if (isTag) {
                continue;
            } else {
                if (start == -1) start = i; 
                st.push(s[i]);
            }
        }
    }

    if (!st.empty()) {
        end = s.length() - 1;
        for (int j = start; j <= end; j++) {
            s[j] = st.top();
            st.pop();
        }
    }

    cout << s;
    return 0;
}