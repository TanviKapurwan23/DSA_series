#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result; // Empty tree

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelNodes(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Determine the index to insert node value based on direction
                int index = leftToRight ? i : (levelSize - 1 - i);
                levelNodes[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(levelNodes);
            leftToRight = !leftToRight; // Toggle the direction for the next level
        }

        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    for (const auto& level : result) {
        cout << "[";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    // Clean up memory (optional, but good practice)
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
