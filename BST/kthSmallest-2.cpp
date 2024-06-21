// Iterative In-order Traversal


#include <stack>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stack;
        TreeNode* current = root;

        while (current != nullptr || !stack.empty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }

            current = stack.top();
            stack.pop();
            k--;
            if (k == 0) {
                return current->val;
            }

            current = current->right;
        }

        return -1; // this line should never be reached if k is valid
    }
};
