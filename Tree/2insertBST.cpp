#include <iostream>

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == nullptr) {
        return new Node(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // return the (unchanged) node pointer
    return root;
}

// Function to print inorder traversal of a binary tree
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print inorder traversal of the BST
    inorder(root);

    return 0;
}
