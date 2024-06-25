// Using Morris Traversal

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = 0;
        TreeNode* current = root;

        while (current != nullptr) {
            if (current->left == nullptr) {
                count++;
                if (count == k) {
                    result = current->val;
                }
                current = current->right;
            } else {
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    predecessor->right = nullptr;
                    count++;
                    if (count == k) {
                        result = current->val;
                    }
                    current = current->right;
                }
            }
        }

        return result;
    }
};
