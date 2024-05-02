#include <iostream>

// Define the ListNode structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Check if the list is empty or has only one node
        if (!head || !head->next) {
            return head; // Return the list as it is
        }
        
        ListNode* current = head; // Pointer to track the current node
        
        // Iterate through the list until the current node or the next node is null
        while (current && current->next) {
            // Check if the current node's value is equal to the next node's value
            if (current->val == current->next->val) {
                ListNode* temp = current->next; // Temporarily store the duplicate node
                current->next = current->next->next; // Skip the duplicate node
                delete temp; // Delete the duplicate node from memory
            } else {
                current = current->next; // Move to the next node if no duplicate is found
            }
        }
        
        return head; // Return the modified linked list with duplicates removed
    }
};


// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sorted linked list [1, 1, 2, 3, 3]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    // Create an instance of the Solution class
    Solution solution;

    // Call the deleteDuplicates function to remove duplicates
    ListNode* modifiedList = solution.deleteDuplicates(head);

    // Print the modified linked list
    std::cout << "Modified Linked List: ";
    printList(modifiedList);

    return 0;
}
