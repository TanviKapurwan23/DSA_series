#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: if both trees are empty, they are considered the same
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // If one of the trees is empty and the other is not, they are not the same
        if (p == nullptr || q == nullptr) {
            return false;
        }
        // If the values of the current nodes are different, the trees are not the same
        if (p->val != q->val) {
            return false;
        }
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    // Create two example binary trees
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution solution;
    bool areSame = solution.isSameTree(p, q);
    cout << "Are the trees the same? " << (areSame ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}
