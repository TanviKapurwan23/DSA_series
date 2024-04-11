#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head; // Handle empty list or single node

        ListNode* dummy = new ListNode(0); // Dummy node to handle cases where head is removed
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            bool isDuplicate = false;

            // Skip all duplicates
            while (curr->next && curr->val == curr->next->val) {
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
                isDuplicate = true;
            }

            if (isDuplicate) {
                // Remove the last duplicate node
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
                continue;
            }

            prev->next = curr;
            prev = prev->next;
            curr = curr->next;
        }

        prev->next = nullptr; // Set the next of the last distinct node to nullptr

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

// Utility function to print a linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
