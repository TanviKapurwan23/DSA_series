#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
}

void swapAtDepth(TreeNode* root, int depth, int currentDepth) {
    if (root == NULL) return;
    if (currentDepth % depth == 0) {
        swap(root->left, root->right);
    }
    swapAtDepth(root->left, depth, currentDepth + 1);
    swapAtDepth(root->right, depth, currentDepth + 1);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    // Build the tree
    TreeNode* root = new TreeNode(1);
    queue<TreeNode*> q;
    q.push(root);
    for (const auto& index : indexes) {
        TreeNode* current = q.front();
        q.pop();
        if (index[0] != -1) {
            current->left = new TreeNode(index[0]);
            q.push(current->left);
        }
        if (index[1] != -1) {
            current->right = new TreeNode(index[1]);
            q.push(current->right);
        }
    }

    vector<vector<int>> results;
    for (int query : queries) {
        swapAtDepth(root, query, 1);
        vector<int> inorderResult;
        inorderTraversal(root, inorderResult);
        results.push_back(inorderResult);
    }

    return results;
}

int main() {
    vector<vector<int>> indexes = {
        {2, 3},
        {-1, -1},
        {-1, -1}
    };
    vector<int> queries = {1};

    vector<vector<int>> result = swapNodes(indexes, queries);
    for (const auto& inorder : result) {
        for (int val : inorder) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
