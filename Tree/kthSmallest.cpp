#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1; // Initialize result variable

        inorderTraversal(root, k, result);

        return result;
    }

private:
    void inorderTraversal(TreeNode* root, int& k, int& result) {
        if (!root) return;

        inorderTraversal(root->left, k, result);

        // Decrement k for each visited node
        if (--k == 0) {
            result = root->val; // Update result when k becomes 0
            return;
        }

        inorderTraversal(root->right, k, result);
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 1;

    Solution solution;
    int result = solution.kthSmallest(root, k);
    cout << "Kth Smallest Value: " << result << endl;

    // Clean up memory (optional, but good practice)
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
