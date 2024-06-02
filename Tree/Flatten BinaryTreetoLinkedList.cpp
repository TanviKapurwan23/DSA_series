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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return; // Empty tree, nothing to flatten
        }

        flattenHelper(root);
    }

private:
    TreeNode* flattenHelper(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* leftTail = flattenHelper(root->left);
        TreeNode* rightTail = flattenHelper(root->right);

        if (leftTail != nullptr) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        if (rightTail != nullptr) {
            return rightTail;
        }

        if (leftTail != nullptr) {
            return leftTail;
        }

        return root;
    }
};

// Function to print the flattened tree (for testing)
void printFlattenedTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printFlattenedTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution solution;
    solution.flatten(root);

    cout << "Flattened tree: ";
    printFlattenedTree(root); // Output: 1 2 3 4 5 6

    return 0;
}
