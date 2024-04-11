
// To remove the nth node from the end of a linked list,  two-pointer approach. One pointer (fast pointer) will be moved ahead by n steps initially, and then both pointers (slow and fast) will be moved simultaneously until the fast pointer reaches the end of the list.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyHead(0); // Dummy head to handle edge cases
        dummyHead.next = head; // Connect dummy head to the original head
        ListNode* slow = &dummyHead; // Slow pointer starting from dummy head
        ListNode* fast = &dummyHead; // Fast pointer starting from dummy head

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            if (!fast->next) return head; // Handle edge case if n is greater than the length of the list
            fast = fast->next;
        }

        // Move slow and fast pointers simultaneously until fast reaches the end
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the nth node by adjusting pointers
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummyHead.next; // Return the head of the modified list
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

    int n = 2;

    Solution sol;
    ListNode* modifiedList = sol.removeNthFromEnd(head, n);

    std::cout << "Modified List: ";
    printList(modifiedList);

    // Clean up the memory
    while (modifiedList) {
        ListNode* temp = modifiedList;
        modifiedList = modifiedList->next;
        delete temp;
    }

    return 0;
}
