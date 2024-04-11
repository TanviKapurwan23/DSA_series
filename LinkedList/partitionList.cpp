#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lessHead = new ListNode(0);          // Dummy head for nodes less than x
        ListNode *lessTail = lessHead;                 // Tail pointer for nodes less than x
        ListNode *greaterEqualHead = new ListNode(0);  // Dummy head for nodes greater than or equal to x
        ListNode *greaterEqualTail = greaterEqualHead; // Tail pointer for nodes greater than or equal to x

        ListNode *curr = head;

        // Traverse the original list and partition nodes into two separate lists
        while (curr)
        {
            if (curr->val < x)
            {
                lessTail->next = curr;
                lessTail = lessTail->next;
            }
            else
            {
                greaterEqualTail->next = curr;
                greaterEqualTail = greaterEqualTail->next;
            }
            curr = curr->next;
        }

        // Merge the two lists
        lessTail->next = greaterEqualHead->next;
        greaterEqualTail->next = nullptr;

        // Get the head of the final list
        ListNode *result = lessHead->next;

        // Clean up memory
        delete lessHead;
        delete greaterEqualHead;

        return result;
    }
};

// Utility function to print a linked list
void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    Solution sol;
    ListNode *result = sol.partition(head, x);

    std::cout << "Result: ";
    printList(result);

    // Clean up the memory
    while (result)
    {
        ListNode *temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
