#include<iostream>
#include <climits>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node(int value){
        this->value = value;
        next = nullptr;
    }

};

class Stack{
    private:
    Node* top;
    int height;

    public:
    Stack(int value){
        Node* newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    void printStack(){
        Node* temp = top;
        while(temp){
            cout<<temp->value<<endl;
            temp = temp->next;
        }
    }

    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop(){
        if(height == 0) return INT_MIN;
        Node* temp = top;
        int poppedValue = top->value;
        top = top->next;
        delete temp;
        height--;
        return poppedValue;


    }
};

int main(){
   Stack* mystack = new Stack(1);
   mystack->push(2);
   mystack->push(3);

   mystack->printStack();
   cout<<"After popping"<<endl;

   mystack->pop();
   mystack->printStack();

   cout<<"After popping"<<endl;
   mystack->pop();
//    cout<<INT_MIN;
}