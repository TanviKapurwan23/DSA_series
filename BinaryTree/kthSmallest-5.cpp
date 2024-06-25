// Augmented BST with Count of Nodes

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    int leftCount; // Number of nodes in the left subtree

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), leftCount(0) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestHelper(root, k);
    }

private:
    int kthSmallestHelper(TreeNode* node, int k) {
        if (node == nullptr) {
            return -1; // this should not happen for valid k
        }

        if (node->leftCount + 1 == k) {
            return node->val;
        } else if (node->leftCount + 1 > k) {
            return kthSmallestHelper(node->left, k);
        } else {
            return kthSmallestHelper(node->right, k - node->leftCount - 1);
        }
    }
};
