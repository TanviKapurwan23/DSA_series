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
    // Helper function to find the height of a tree and update the diameter.
    int heightAndDiameter(Node* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }

        // Calculate the height of the left and right subtrees.
        int leftHeight = heightAndDiameter(node->left, diameter);
        int rightHeight = heightAndDiameter(node->right, diameter);

        // Update the diameter if the path through the current node is larger.
        diameter = max(diameter, leftHeight + rightHeight + 1);

        // Return the height of the tree rooted at the current node.
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int diameter = 0;
        heightAndDiameter(root, diameter);
        return diameter;
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
    int treeDiameter = solution.diameter(root);
    cout << "Diameter of the tree: " << treeDiameter << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
