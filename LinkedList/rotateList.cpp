// Find the length of the linked list and calculate the effective value of k (k modulo length of the list).
// If k is zero or the list is empty, return the original list.
// Traverse the list to find the (length - k)th node and the last node.
// Set the next pointer of the last node to point to the head of the original list, making it circular.
// Update the head pointer to the node at position (length - k) + 1.
// Set the next pointer of the (length - k)th node to nullptr, breaking the circular structure.

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head; // Return the original list if k is zero or the list is empty

        int length = 1;
        ListNode* tail = head;
        while (tail->next) { // Calculate the length of the list and find the last node
            length++;
            tail = tail->next;
        }

        k = k % length; // Effective value of k after taking modulo

        if (k == 0) return head; // Return the original list if k becomes zero after taking modulo

        ListNode* curr = head;
        for (int i = 1; i < length - k; i++) { // Traverse to the (length - k)th node
            curr = curr->next;
        }

        tail->next = head; // Make the list circular
        head = curr->next; // Update the head pointer
        curr->next = nullptr; // Break the circular structure

        return head;
    }
};

// Utility function to print a linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution sol;
    ListNode* rotatedList = sol.rotateRight(head, k);

    std::cout << "Rotated List: ";
    printList(rotatedList);

    // Clean up the memory
    while (rotatedList) {
        ListNode* temp = rotatedList;
        rotatedList = rotatedList->next;
        delete temp;
    }

    return 0;
}
