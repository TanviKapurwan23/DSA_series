#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void diagonalTraversalUtil(Node* root, int diagonalDistance, map<int, vector<int>>& diagonalMap) {
    if (root == nullptr) {
        return;
    }

    // Update the diagonal map with the current node's value
    diagonalMap[diagonalDistance].push_back(root->data);

    // Traverse the left subtree with increased diagonal distance
    diagonalTraversalUtil(root->left, diagonalDistance + 1, diagonalMap);

    // Traverse the right subtree with the same diagonal distance
    diagonalTraversalUtil(root->right, diagonalDistance, diagonalMap);
}

vector<int> diagonal(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    // Map to store nodes at each diagonal distance
    map<int, vector<int>> diagonalMap;

    // Perform diagonal traversal starting from the root
    diagonalTraversalUtil(root, 0, diagonalMap);

    // Extract the nodes from the diagonal map in the correct order
    for (const auto& pair : diagonalMap) {
        for (int val : pair.second) {
            result.push_back(val);
        }
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

    vector<int> diagonalResult = diagonal(root);

    cout << "Diagonal Traversal: ";
    for (int val : diagonalResult) {
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
