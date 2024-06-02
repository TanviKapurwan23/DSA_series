#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(NULL), right(NULL) {}
    
    
    //Node(int x)
    // This defines a constructor for the Node class that takes a single integer parameter x.


    // : data(x), left(NULL), right(NULL)
    // This is the initializer list, which initializes the member variables of the Node class before the constructor body executes.




};

int height(Node* root){
    if(root == NULL){
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main(){
    
    Node* root = new Node(1);
    root->left = new Node(1);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"The Height of the tree:"<<height(root)<<endl;
    return 0;
}