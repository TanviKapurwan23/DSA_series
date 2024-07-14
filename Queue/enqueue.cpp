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

class Queue{
    private:
    Node* first;
    Node* last;
    int length;

    public:
    Queue(int value){
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    void printQueue(){
        Node* temp = first;
        while(temp){
            cout<<temp->value<<endl;
            temp = temp->next;
        }
    }

    void getFirst(){
        cout<<"First :"<<first->value<<endl;
    }

    void getLast(){
        cout<<"Last :"<<last->value<<endl;
    }

    void getLength(){
        cout<<"Length :"<<length<<endl;
    }

    void enqueue(int value){
      Node* newNode = new Node(value);
      if(length == 0){
        first = newNode;
        last = newNode;
      } else{
        last->next = newNode;
        last = newNode;
      }
      length++;

    }


};

int main(){

    Queue* myQueue = new Queue(0);

    myQueue->enqueue(1);
    myQueue->enqueue(2);

    myQueue->printQueue();



    return 0;
}