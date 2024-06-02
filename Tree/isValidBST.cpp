#include <iostream>
#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }

private:
    bool isValidBSTHelper(TreeNode* node, long long minValue, long long maxValue) {
        if (!node) return true; // An empty tree is a valid BST

        // Check if the node's value is within the valid range
        if (node->val <= minValue || node->val >= maxValue) return false;

        // Recursively check left and right subtrees with updated ranges
        return isValidBSTHelper(node->left, minValue, node->val) &&
               isValidBSTHelper(node->right, node->val, maxValue);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isValidBST(root);
    cout << "Is Valid BST: " << (result ? "true" : "false") << endl;

    // Clean up memory (optional, but good practice)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
