#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
     data = val;
     next = nullptr;
     prev = nullptr;
    }
};

class doublyLinkedList{
   private:
     Node* head;
   public:
   
     doublyLinkedList(){
        head = nullptr;
     }
     void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
           head = newNode;
        } else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
     }
      void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
   doublyLinkedList* myDLL = new doublyLinkedList();
   myDLL->insertAtHead(1);
   myDLL->insertAtHead(2);
   myDLL->display();

}