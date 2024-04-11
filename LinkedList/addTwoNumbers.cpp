// You can add two numbers represented as linked lists by iterating through both lists simultaneously and performing the addition digit by digit, considering carry values.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0); // Dummy head to simplify handling of result list
        ListNode* curr = &dummyHead; // Pointer to the current node in the result list
        int carry = 0; // Carry value for addition

        while (l1 || l2 || carry) {
            int sum = carry; // Initialize sum with the current carry value
            if (l1) {
                sum += l1->val; // Add the value of l1 to sum if l1 is not nullptr
                l1 = l1->next; // Move to the next node in l1
            }
            if (l2) {
                sum += l2->val; // Add the value of l2 to sum if l2 is not nullptr
                l2 = l2->next; // Move to the next node in l2
            }

            carry = sum / 10; // Calculate the new carry value
            curr->next = new ListNode(sum % 10); // Create a new node with the digit of sum
            curr = curr->next; // Move to the next node in the result list
        }

        return dummyHead.next; // Return the next node after the dummy head (the actual result list)
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
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    std::cout << "Output: ";
    printList(result);

    // Clean up the memory
    while (l1) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
