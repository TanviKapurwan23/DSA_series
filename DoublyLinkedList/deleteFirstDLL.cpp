#include<iostream>
using namespace std;

class Node{
    public:
      int value;
      Node* next;
      Node* prev;

      Node(int value){
        this->value = value;
        next = nullptr;
        prev = nullptr;
      }
};

class DoublyLinkedList{
  private:
     Node* head;
     Node* tail;
     int length;

  public:
     DoublyLinkedList(int value)
     {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList(){
       Node* temp = head;
       while(temp){
        cout<<temp->value<<endl;
        temp = temp->next;
       }
    }

    void append(int value){
      Node* newNode = new Node(value);
      if(length == 0){
        head = newNode;
        tail = newNode;
      } else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
      }
      length++;
    }

    void deleteLast(){
        if(length == 0) return;
        Node* temp = tail;
        if(length == 1){
            head = nullptr;
            tail = nullptr;
        } else{
            tail = tail->prev;
            tail->next = nullptr;     
        }
        delete temp;
            length--;
    }

    void prepend(int value){
        Node* newNode = new Node(value);
        if(length == 0){
            head = newNode;
            tail = newNode;
        } else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;

        }
        length++;
    }

    void deleteFirst(){
        if(length == 0) return;
        Node* temp = head;
        if(length == 1){
            head = nullptr;
            tail = nullptr;
        }else{
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

   




};

int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(2);

  
    myDLL->append(3);

    myDLL->prepend(1);


    myDLL->printList();
    cout<<"After delete first"<<endl;
    myDLL->deleteFirst();
    myDLL->printList();

    cout<<"After delete first"<<endl;
    myDLL->deleteFirst();
    myDLL->printList();

    cout<<"After delete first"<<endl;
    myDLL->deleteFirst();
    myDLL->printList();


    




    return 0;
}