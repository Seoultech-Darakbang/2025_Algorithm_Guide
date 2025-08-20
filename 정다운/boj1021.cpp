#include <iostream>
#include <vector>
using namespace std;

struct Deque
{
    vector<int> vec;
    int front;
    int rear;
    int size;

    void init(int n)
    {
        vec.resize(n+1);
        front = 0;
        rear = 0;
        size = n+1;
    }
    bool isempty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }
    bool isfull()
    {
        if (front == (rear + 1) % size)
        {
            return true;
        }
        return false;
    }
    void pushFront(int data)
    {
        if (!isfull())
        {
            if (front == 0)
            {
                vec[front] = data;
                front = size-1;
            }
            else
            {
                vec[front] = data;
                front = front - 1;
            }
        }
    }
    void pushRear(int data)
    {
        if (!isfull())
        {
            rear = (rear + 1) % size;
            vec[rear] = data;
        }
    }
    int popFront()
    {
        if (!isempty())
        {
            front = (front + 1) % size;
            return vec[front];
        }
        return -1;
    }
    int popRear()
    {
        if (!isempty())
        {
            int temp = vec[rear];
            if (rear == 0)
            {
                rear = size - 1;
            }
            else
            {
                rear = (rear - 1) % size;
            }
            return temp;
        }
        return -1;
    }
    int getFront()
    {
        if (isempty())
        {
            return -1;
        }
        return vec[(front+1)%size];
    }
    void moveLeft()
    {
        int temp = popFront();
        pushRear(temp);
    }
    void moveRight()
    {
        int temp = popRear();
        pushFront(temp);
    }
};

int main()
{
    Deque deque;
    int n, m, count = 0;
    cin >> n >> m;
    deque.init(n);
    for (int i = 0; i < n; i++)
    {
        deque.pushRear(i + 1);
    }
    Deque temp = deque;
    for (int i = 0; i < m; i++)
    {
        Deque temp1 = temp, temp2 = temp;
        int find, countLeft = 0, countRight = 0;
        cin >> find;
        if (temp.getFront() == deque.vec[find])
        {
            temp.popFront();
            continue;
        }
        while (temp1.getFront() != deque.vec[find])
        {
            temp1.moveLeft();
            countLeft++;
        }
        temp1.popFront();
        while (temp2.getFront() != deque.vec[find])
        {
            temp2.moveRight();
            countRight++;
        }
        temp2.popFront();
        if (countLeft > countRight)
        {
            count += countRight;
            temp = temp2;
        }
        else
        {
            count += countLeft;
            temp = temp1;
        }
    }
    cout<<count<<endl;
}