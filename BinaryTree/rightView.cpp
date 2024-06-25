#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> rightView(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        // Traverse each level and add the rightmost node to the result vector.
        for (int i = 0; i < n; ++i) {
            Node* current = q.front();
            q.pop();

            if (i == n - 1) {  // Check if it's the rightmost node at this level.
                result.push_back(current->data);
            }

            // Add left child to queue.
            if (current->left != nullptr) {
                q.push(current->left);
            }

            // Add right child to queue.
            if (current->right != nullptr) {
                q.push(current->right);
            }
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

    vector<int> rightViewResult = rightView(root);

    cout << "Right View of the tree: ";
    for (int val : rightViewResult) {
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
