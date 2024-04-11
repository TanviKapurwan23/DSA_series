#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // Count the number of nodes in the current group
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        // If the number of nodes is less than k, no reversal is needed
        if (count < k) {
            return head;
        }

        // Reverse the current group of k nodes
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        curr = head;
        count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursively reverse the remaining part of the list in groups of k nodes
        if (next) {
            head->next = reverseKGroup(next, k);
        }

        return prev; // Return the new head of the reversed group
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

    int k = 3;

    Solution sol;
    ListNode* reversedList = sol.reverseKGroup(head, k);

    std::cout << "Reversed List in Groups of " << k << ": ";
    printList(reversedList);

    // Clean up the memory
    while (reversedList) {
        ListNode* temp = reversedList;
        reversedList = reversedList->next;
        delete temp;
    }

    return 0;
}
