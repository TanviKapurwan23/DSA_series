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

vector<int> zigZagTraversal(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true; // Flag to track the traversal direction

    while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);

        for (int i = 0; i < n; ++i) {
            Node* current = q.front();
            q.pop();

            // Determine the position to insert the node value based on the traversal direction
            int index = leftToRight ? i : (n - i - 1);
            level[index] = current->data;

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        // Toggle the traversal direction for the next level
        leftToRight = !leftToRight;

        // Append the current level to the result vector
        result.insert(result.end(), level.begin(), level.end());
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

    vector<int> zigzagResult = zigZagTraversal(root);

    cout << "Zigzag Traversal: ";
    for (int val : zigzagResult) {
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
