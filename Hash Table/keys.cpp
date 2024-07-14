#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable {
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            dataMap[i] = nullptr;
        }
    }

    void printTable() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ":" << endl;
            if (dataMap[i]) {
                Node* temp = dataMap[i];
                while (temp) {
                    cout << " {" << temp->key << " , " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }

    int hash(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE;
        }
        return hash;
    }

    void set(string key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if (dataMap[index] == nullptr) {
            dataMap[index] = newNode;
        } else {
            Node* temp = dataMap[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int get(string key) {
        int index = hash(key);
        Node* temp = dataMap[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;  // Return -1 if key is not found
    }

    vector<string> keys() {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++) {
            Node* temp = dataMap[i];
            while (temp != nullptr) {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return allKeys;
    }
};

int main() {
    HashTable* myHashtable = new HashTable();
    myHashtable->set("paints", 100);
    myHashtable->set("bolts", 50);
    myHashtable->set("nails", 80);
    myHashtable->set("tile", 140);
    myHashtable->set("lumber", 80);

    vector<string> myKeys = myHashtable->keys();

    for (vector<string>::iterator it = myKeys.begin(); it != myKeys.end(); ++it) {
        cout << *it << " ";
    }

    delete myHashtable;

    return 0;
}
