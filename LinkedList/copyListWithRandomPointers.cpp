// Create a mapping between original nodes and their corresponding copied nodes.
// Iterate through the original list to create new nodes and set their values. Also, update the mapping for each node.
// Iterate through the original list again to set the next and random pointers of the copied nodes based on the mapping.

#include <iostream>
#include <unordered_map>

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        std::unordered_map<Node*, Node*> nodeMap; // Mapping between original nodes and copied nodes
        Node* curr = head;

        // Create new nodes and set their values, updating the mapping
        while (curr) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        // Set next and random pointers of the copied nodes based on the mapping
        while (curr) {
            nodeMap[curr]->next = nodeMap[curr->next];
            nodeMap[curr]->random = nodeMap[curr->random];
            curr = curr->next;
        }

        return nodeMap[head]; // Return the head of the copied list
    }
};

// Utility function to print a linked list with random pointers
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        std::cout << "[" << curr->val;
        if (curr->random) {
            std::cout << "," << curr->random->val;
        } else {
            std::cout << ",null";
        }
        std::cout << "] -> ";
        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head;

    Solution sol;
    Node* copiedList = sol.copyRandomList(head);

    std::cout << "Original List with Random Pointers: ";
    printList(head);

    std::cout << "Copied List with Random Pointers: ";
    printList(copiedList);

    // Clean up the memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    while (copiedList) {
        Node* temp = copiedList;
        copiedList = copiedList->next;
        delete temp;
    }

    return 0;
}
