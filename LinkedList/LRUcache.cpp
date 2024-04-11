#include <iostream>
#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    std::unordered_map<int, Node*> cacheMap;
    Node* head;
    Node* tail;
    int capacity;

    void moveToHead(Node* node) {
        // Move the given node to the head of the linked list
        if (node == head) {
            return;
        }

        if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
    }

    void removeTail() {
        // Remove the tail node from the linked list and the cache map
        cacheMap.erase(tail->key);
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}

    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* node = cacheMap[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* node = cacheMap[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cacheMap[key] = newNode;
            if (!head) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            if (cacheMap.size() > capacity) {
                removeTail();
            }
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // Output: 1
    cache.put(3, 3);
    std::cout << cache.get(2) << std::endl; // Output: -1
    cache.put(4, 4);
    std::cout << cache.get(1) << std::endl; // Output: -1
    std::cout << cache.get(3) << std::endl; // Output: 3
    std::cout << cache.get(4) << std::endl; // Output: 4

    return 0;
}
