#include <iostream>

struct TreeNode {
    int val; // Value stored in the node
    TreeNode *left; // Pointer to the left child node
    TreeNode *right; // Pointer to the right child node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}     // Constructor for creating a new node

};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both trees are empty, they are the same
        if (!p && !q) {
            return true;
        }
        // If one tree is empty and the other is not, they are different
        if (!p || !q) {
            return false;
        }
        // Check if the current nodes' values are equal
        if (p->val != q->val) {
            return false;
        }
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution solution;

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = solution.isSameTree(p, q);
    std::cout << std::boolalpha << "Output: " << result << std::endl;

    // Clean up memory
    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    return 0;
}
