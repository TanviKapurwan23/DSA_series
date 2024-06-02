#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//recursive approach 


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true; // Empty tree is symmetric
        }
        return isSymmetricHelper(root->left, root->right);
    }

private:
    bool isSymmetricHelper(TreeNode* leftSubtree, TreeNode* rightSubtree) {
        if (leftSubtree == nullptr && rightSubtree == nullptr) {
            return true; // Both subtrees are empty, symmetric
        }
        if (leftSubtree == nullptr || rightSubtree == nullptr) {
            return false; // One subtree is empty, not symmetric
        }
        if (leftSubtree->val != rightSubtree->val) {
            return false; // Values of nodes are different, not symmetric
        }

        // Recursively check if the left subtree of leftSubtree is symmetric with the right subtree of rightSubtree
        // and if the right subtree of leftSubtree is symmetric with the left subtree of rightSubtree
        return isSymmetricHelper(leftSubtree->left, rightSubtree->right) &&
               isSymmetricHelper(leftSubtree->right, rightSubtree->left);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    Solution solution;
    bool isSymmetric1 = solution.isSymmetric(root1);
    cout << "Is the tree symmetric? " << (isSymmetric1 ? "Yes" : "No") << endl; // Output: Yes

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);

    bool isSymmetric2 = solution.isSymmetric(root2);
    cout << "Is the tree symmetric? " << (isSymmetric2 ? "Yes" : "No") << endl; // Output: No

    return 0;
}
