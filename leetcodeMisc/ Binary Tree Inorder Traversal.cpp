#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorder(TreeNode* root, std::vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        inorder(root->left, result); // Visit left subtree
        result.push_back(root->val); // Visit root node
        inorder(root->right, result); // Visit right subtree
    }
    
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        inorder(root, result);
        return result;
    }
};
