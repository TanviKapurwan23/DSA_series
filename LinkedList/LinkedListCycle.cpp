// using the Floyd's Cycle Detection Algorithm, also known as the Tortoise and Hare algorithm, to determine if there is a cycle in a linked list.

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
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false; // If the list is empty or has only one node, there can't be a cycle

        ListNode *slow = head;
        ListNode *fast = head->next; // Start with different speeds to detect a cycle

        while (fast && fast->next)
        {
            if (slow == fast)
                return true;         // If slow and fast pointers meet, there is a cycle
            slow = slow->next;       // Move slow pointer by one step
            fast = fast->next->next; // Move fast pointer by two steps
        }

        return false; // If fast pointer reaches the end, there is no cycle
    }
};

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    Solution sol;
    bool result = sol.hasCycle(head);

    std::cout << "Output: " << std::boolalpha << result << std::endl;

    // Clean up the memory
    ListNode *curr = head;
    while (curr)
    {
        ListNode *temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
