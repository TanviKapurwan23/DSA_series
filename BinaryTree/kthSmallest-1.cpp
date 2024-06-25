//  Recursive In-order Traversal

class Solution {
private:
    int count = 0;
    int result = INT_MIN;

    void inOrderTraversal(TreeNode* node, int k) {
        if (node == nullptr) return;

        inOrderTraversal(node->left, k);

        count++;
        if (count == k) {
            result = node->val;
            return;
        }

        inOrderTraversal(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root, k);
        return result;
    }
};
