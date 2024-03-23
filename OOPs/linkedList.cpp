
/*
Array Limitation:

1 fixed size
2 contiguous block of memory
3 Inserting or deleting is costly


Linked List:

Multiple block of memory linked to each other
1 size can be modified
2 non-contiguous memory
3 Insertion and deletion at any point is easier


NODE      Data  Next

1 20k     2 30k     3 40k    4 NULL

Head


*/
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val) // Constructor
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head; // first node
    head = n;
}

void insertAtTail(node *&head, int val)
{

    node *n = new node(val);

    if (head == NULL) // if empty LL
    {
        head = n;
        return;
    }

    node *temp = head; // Pointer
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n; // last element
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;

    delete todelete;
}

void deletion(node *&head, int val)
{

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void display(node *head) // by value
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtHead(head, 4);
    display(head);
    cout << search(head, 5) << endl;
    cout << search(head, 3) << endl;
    // deletion(head, 3);
    deleteAtHead(head);
    display(head);

    return 0;
}

/*
OUTPUT:

1->2->3->NULL
4->1->2->3->NULL
0
1
1->2->3->NULL
*/