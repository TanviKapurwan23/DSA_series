/*
1 2 3

2 1 3

Build Tree from preorder and inorder

Pick element from preorder and create a node
Increment Preorder idx
Search for picked element's pos in inorder
Call to build left subtree from inorder's 0 to pos-1
Call to build right subtree from inorder pos+1 to n
return node


*/
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


int main()
{

    int preorder[] = {1, 2, 3, 4, 5};
    int inorder[] = {4, 2, 1, 5, 3};
}
