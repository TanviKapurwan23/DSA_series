#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> bottomView(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    queue<pair<Node*, int>> q;
    map<int, int> hdMap; // Map to store horizontal distance and node values

    q.push({root, 0}); // Root has horizontal distance 0

    while (!q.empty()) {
        Node* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Update the horizontal distance map with the latest node at each horizontal distance
        hdMap[hd] = node->data;

        if (node->left) q.push({node->left, hd - 1}); // Decrease horizontal distance for left child
        if (node->right) q.push({node->right, hd + 1}); // Increase horizontal distance for right child
    }

    // Extract node values from the horizontal distance map in the correct order
    for (const auto& pair : hdMap) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    // Creating a sample tree:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> bottomViewResult = bottomView(root);

    cout << "Bottom View of the tree: ";
    for (int val : bottomViewResult) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
