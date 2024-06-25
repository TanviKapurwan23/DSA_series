#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to calculate the height of a binary tree
int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(Node* root) {
    if (root == nullptr) {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Check if the height difference is at most 1 and both left and right subtrees are balanced
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    // Creating a sample tree:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    bool balanced = isBalanced(root);

    cout << "Is the tree balanced? " << (balanced ? "Yes" : "No") << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
