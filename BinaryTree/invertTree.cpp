#include <iostream>
#include <queue>
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
    // Function to invert a binary tree.
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;  // If tree is empty, return nullptr
        }

        // Swap the left and right subtrees recursively
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }
};

// Helper function to print the level-order traversal of the tree
void printLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}

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

    cout << "Original tree: ";
    printLevelOrder(root);

    Solution solution;
    TreeNode* invertedRoot = solution.invertTree(root);

    cout << "Inverted tree: ";
    printLevelOrder(invertedRoot);

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
