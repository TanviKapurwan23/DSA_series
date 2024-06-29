#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    
    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead() {
        if (head != nullptr) {
            cout << "Head: " << head->value << endl;
        } else {
            cout << "Head is null" << endl;
        }
    }

    void getTail() {
        if (tail != nullptr) {
            cout << "Tail: " << tail->value << endl;
        } else {
            cout << "Tail is null" << endl;
        }
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
};

int main() {
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->append(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(5);
    
    myLinkedList->printList();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    delete myLinkedList; // Cleanup to prevent memory leak
    return 0;
}

