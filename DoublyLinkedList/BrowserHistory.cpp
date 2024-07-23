#include <iostream>
#include <string>
#include <deque>

using namespace std;

class BrowserHistory {
private:
    struct Node {
        string url;
        Node* prev;
        Node* next;
        Node(string u) : url(u), prev(nullptr), next(nullptr) {}
    };
    
    Node* current; // Points to the current page
    Node* head;    // Points to the head of the history
    Node* tail;    // Points to the tail of the history

public:
    BrowserHistory(string homepage) {
        head = tail = current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        if (current) {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
            // Remove any forward history when a new page is visited
            Node* temp = current->next;
            while (temp) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }
    }
    
    string back(int steps) {
        while (steps-- && current->prev) {
            current = current->prev;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while (steps-- && current->next) {
            current = current->next;
        }
        return current->url;
    }
};

// Helper function to demonstrate the BrowserHistory class
int main() {
    BrowserHistory browser("homepage.com");
    browser.visit("page1.com");
    browser.visit("page2.com");
    cout << "Current page: " << browser.back(1) << endl; // Output: page1.com
    cout << "Current page: " << browser.back(1) << endl; // Output: homepage.com
    cout << "Current page: " << browser.forward(1) << endl; // Output: page1.com
    cout << "Current page: " << browser.visit("page3.com") << endl; // No output, just visiting
    cout << "Current page: " << browser.forward(2) << endl; // Output: page3.com
    cout << "Current page: " << browser.back(2) << endl; // Output: page1.com
    
    return 0;
}
