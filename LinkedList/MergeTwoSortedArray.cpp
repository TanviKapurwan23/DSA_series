// comparing the values of nodes from both lists and merging them in ascending order.

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0); // Dummy head to simplify handling of merged list
        ListNode* curr = &dummyHead; // Pointer to the current node in the merged list

        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1; // Attach list1 node to the merged list
                list1 = list1->next; // Move to the next node in list1
            } else {
                curr->next = list2; // Attach list2 node to the merged list
                list2 = list2->next; // Move to the next node in list2
            }
            curr = curr->next; // Move to the next node in the merged list
        }

        // Attach the remaining nodes from list1 or list2 (if any)
        curr->next = list1 ? list1 : list2;

        return dummyHead.next; // Return the next node after the dummy head (the merged list)
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
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution sol;
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    // Clean up the memory
    while (list1) {
        ListNode* temp = list1;
        list1 = list1->next;
        delete temp;
    }
    while (list2) {
        ListNode* temp = list2;
        list2 = list2->next;
        delete temp;
    }
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
