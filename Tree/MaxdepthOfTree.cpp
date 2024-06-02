#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0; // Base case: empty tree has depth 0
        } else {
            // Recursively find the maximum depth of left and right subtrees
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);

            // Return the maximum of left and right subtree depths, plus 1 for the root node
            return max(leftDepth, rightDepth) + 1;
        }
    }
};

int main() {
    // Create the example binary tree: [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int depth = solution.maxDepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl; // Output: 3

    return 0;
}
