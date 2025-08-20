#include <iostream>
#include <string>
using namespace std;

struct Deque {
    int arr[10000];
    int first;
    int last;

    void init() {
        first = last = 5000;
    }
    bool empty() {
        if(first == last) {
            return true;
        }
        return false;
    }
    void push_front(int data) {
        arr[first--] = data; 
    }
    void push_back(int data) {
        arr[++last] = data;
    }
    int pop_front() {
        if(empty()) {
            return -1;
        }
        return arr[++first];
    }
    int pop_back() {
        if(empty()) {
            return -1;
        }
        return arr[last--];
    }
    int size() {
        return last - first;
    }
    int front() {
        if(empty()) {
            return -1;
        }
        return arr[first+1];
    }
    int back() {
        if(empty()) {
            return -1;
        }
        return arr[last];
    }
};

int main() {
    int n;
    string str;
    cin>>n;
    struct Deque deq;
    deq.init();

    for(int i=0; i<n; i++) {
        int num;
        cin>>str;
        if(str=="push_front") {
            cin>>num;
            deq.push_front(num);
        }
        if(str=="push_back") {
            cin>>num;
            deq.push_back(num);
        }
        if(str=="pop_front") {
            cout<<deq.pop_front()<<endl;
        }
        if(str=="pop_back") {
            cout<<deq.pop_back()<<endl;
        }
        if(str=="size") {
            cout<<deq.size()<<endl;
        }
        if(str=="empty") {
            cout<<deq.empty()<<endl;
        }
        if(str=="front") {
            cout<<deq.front()<<endl;
        }
        if(str=="back") {
            cout<<deq.back()<<endl;
        }
    }
}