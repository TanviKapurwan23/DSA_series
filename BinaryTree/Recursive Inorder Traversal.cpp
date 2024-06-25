#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Recursive function for inorder traversal
    void inorderTraversalRecursive(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversalRecursive(root->left);
        cout << root->data << " ";
        inorderTraversalRecursive(root->right);
    }
};

int main() {
    // Creating a sample tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    cout << "Recursive Inorder Traversal: ";
    solution.inorderTraversalRecursive(root);
    cout << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
