#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> reverseLevelOrder(Node* root) {
    vector<int> result;
    if (root == nullptr) return result; // If the tree is empty, return an empty vector

    queue<Node*> q;
    stack<int> s;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        s.push(current->data); // Push the current node's data onto the stack

        // Enqueue right child first (so that left child is processed first when reversed)
        if (current->right != nullptr) {
            q.push(current->right);
        }

        // Enqueue left child
        if (current->left != nullptr) {
            q.push(current->left);
        }
    }

    // Transfer the elements from the stack to the result vector
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = reverseLevelOrder(root);
    cout << "Reverse level order traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
