#include <iostream>
using namespace std;

#define n 20

class queue   
{
    int *arr;
    int front;
    int back;

public:
    queue()   // Constructor
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x)
    {
        if (back == n - 1)         // No more space
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        back++;           
        arr[back] = x;

        if (front == -1)      // First element
        {
            front++;
        }
    }
    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "No elements in queue" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No elements in queue" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();
 
    cout << q.peek() << endl;
    q.pop();

    cout << q.empty() << endl;

    return 0;
}