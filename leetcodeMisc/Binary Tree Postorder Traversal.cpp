#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        postorderHelper(root, result);
        return result;
    }

private:
    void postorderHelper(TreeNode* node, std::vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        postorderHelper(node->left, result); // Recur on the left subtree
        postorderHelper(node->right, result); // Recur on the right subtree
        result.push_back(node->val); // Visit the current node after visiting left and right subtrees
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    std::vector<int> result = solution.postorderTraversal(root);

    std::cout << "Postorder Traversal: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Free memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
