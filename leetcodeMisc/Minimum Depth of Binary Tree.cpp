#include <iostream>
#include <algorithm>

// depth-first search (DFS) algorithm 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        // If the root is null, the depth is 0
        if (root == nullptr) {
            return 0;
        }

        // If the node is a leaf node, the depth is 1
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int leftDepth = root->left ? minDepth(root->left) : INT_MAX; // Recurse on the left child
        int rightDepth = root->right ? minDepth(root->right) : INT_MAX; // Recurse on the right child

        return 1 + std::min(leftDepth, rightDepth); // Minimum depth is 1 plus the minimum of left and right depths
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    std::cout << "Minimum Depth: " << solution.minDepth(root) << std::endl;

    // Free memory
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root
