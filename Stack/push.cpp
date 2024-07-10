#include<iostream>
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

    void getTop(){
        cout<<"Top : "<<top->value<<endl;
    }

    void getHeight(){
        cout<<"Height : t"<<height<<endl;
    }
};


int main(){
    Stack* mystack = new Stack(4);
  
    mystack->push(5);
    mystack->push(6);
    mystack->printStack();

    return 0;
}