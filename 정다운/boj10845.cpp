#include <iostream>
#include <string>
using namespace std;

struct Queue
{
    int arr[10000];
    int first;
    int last;

    void init() {
        first = 0;
        last = 0;
    }
    bool empty() {
        if(first == last) {
            return true;
        }
        return false;
    }
    void push(int data) {
        arr[last++] = data;
    }
    int pop() {
        if(empty()) {
            return -1;
        }
        return arr[first++];
    }
    int size() {
        return last-first;
    }
    int front() {
        if(empty()) {
            return -1;
        }
        return arr[first];
    }
    int back() {
        if(empty()) {
            return -1;
        }
        return arr[last-1];
    }
};

int main() {
    int n;
    string str;
    cin>>n;
    struct Queue q;
    q.init();

    for(int i=0; i<n; i++) {
        int num;
        cin>>str;
        
        if(str=="push") {
            cin>>num;
            q.push(num);
        }
        if(str=="pop") {
            cout<<q.pop()<<endl;
        }
        if(str=="size") {
            cout<<q.size()<<endl;
        }
        if(str=="empty") {
            cout<<q.empty()<<endl;
        }
        if(str=="front") {
            cout<<q.front()<<endl;
        }
        if(str=="back") {
            cout<<q.back()<<endl;
        }
    }
}