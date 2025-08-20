#include <iostream>
#include <string>
using namespace std;

struct Stack {
    int arr[10000];
    int last;

    void init() { last = -1; }
    int size() { return last + 1; }
    bool empty() {
        if (last < 0) {
            return true;
        }
        return false;
    }
    void push(int data) { arr[++last] = data; }
    int pop() {
        if (empty()) {
            return -1;
        }
        return arr[last--];
    }
    int top() {
        if (empty()) {
            return -1;
        }
        return arr[last];
    }
};

int main() {
    int n;
    string str;
    struct Stack s;
    s.init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> str;
        if (str == "push") {
            cin >> num;
            s.push(num);
        }
        if (str == "pop") {
            cout << s.pop() << endl;
        }
        if (str == "size") {
            cout << s.size() << endl;
        }
        if (str == "empty") {
            cout << s.empty() << endl;
        }
        if (str == "top") {
            cout << s.top() << endl;
        }
    }
}