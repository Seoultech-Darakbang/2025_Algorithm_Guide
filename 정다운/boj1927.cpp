/*
Heap: 이진 트리 자료구조
min heap: 부모노드가 자식노드보다 작음
max heap: 부모노드가 자식노드보다 큼
*/

#include <iostream>
#include <vector>
using namespace std;

struct Minheap{
    vector<int> heap;
    int heapCount = 0;
    void init() {
        heap.push_back(0);
    }

    bool isempty() {
        return heapCount==0;
    }

    void push(int data) {
        heapCount++;
        if(heap.size() <= heapCount) {
            heap.push_back(data);
        }
        else heap[heapCount] = data;
        int child = heapCount;
        int parent = child / 2;
        while(child>1) {
            if(heap[parent]>heap[child]) {
                swap(heap[parent], heap[child]);
                child = parent;
                parent = child / 2;
            }
            else {
                break;
            }
        }
    }

    int pop() {
        if(isempty()) {
            return 0;
        }
        int temp = heap[1];
        heap[1] = heap[heapCount];
        heapCount--;

        int parent = 1;
        int child = parent * 2;

        while(child <= heapCount) {
            if(heap[child] > heap[child + 1]){
                child++;
            }
            if(heap[parent] > heap[child]) {
                swap(heap[parent], heap[child]);
                parent = child;
                child = parent * 2;
            }
            else {
                break;
            }
        }
        return temp;
    }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    Minheap heap;
    heap.init();
    int n;
    cin>>n;
    vector<int> result;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        if(x == 0) {
            result.push_back(heap.pop());
        }
        else {
            heap.push(x);
        }
    } 
    for(auto i : result) {
        cout<<i<<'\n';
    }
}
