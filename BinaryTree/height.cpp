#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
    // Function to find the height of a binary tree.
    int height(struct Node* node) {
        // Base case: If the node is null, return 0.
        if (node == nullptr) {
            return 0;
        }
        
        // Recursive case: Compute the height of the left and right subtrees.
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        // The height of the current node is 1 + the maximum of the heights of its subtrees.
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    // Creating a sample tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution;
    int treeHeight = solution.height(root);
    cout << "Height of the tree: " << treeHeight << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
