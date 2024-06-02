#include <iostream>

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

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "PREORDER" << endl;
    preorder(root);

    cout<<"INORDER"<<endl;
    inorder(root);


    cout << "POSTORDER" << endl;
    postorder(root);

    return 0;
}
/*

              OUTPUT
PREORDER: 
1 2 4 5 3 6 7 
INORDER: 
4 2 5 1 6 3 7 
POSTORDER: 
4 5 2 6 7 3 1 


*/
/*
Preorder:
Root
Left Subtree
Right Subtree

Inorder:
Left Subtree
Root
Right Subtree
4 2 5 1 6 3 7

PostOrder:
Left Subtree
Right Subtree
Root

4 5 2 6 7 3 1
*/