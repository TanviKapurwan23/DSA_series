#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* lca(Node* root, int v1, int v2) {
    // Base case: if root is NULL, return NULL
    if (root == NULL) return NULL;

    // If either v1 or v2 matches the root's key, return root
    if (root->data == v1 || root->data == v2) return root;

    // Look for keys in left and right subtrees
    Node* left_lca = lca(root->left, v1, v2);
    Node* right_lca = lca(root->right, v1, v2);

    // If both of the above calls return non-NULL, then one key
    // is present in one subtree and the other is present in the other,
    // So this node is the LCA
    if (left_lca != NULL && right_lca != NULL) return root;

    // Otherwise, check if left subtree or right subtree is the LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main() {
    // Create a binary tree
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    // Find LCA
    Node* ancestor = lca(root, 5, 1);
    if (ancestor != NULL)
        cout << "LCA(5, 1): " << ancestor->data << endl;
    else
        cout << "Keys are not present in the tree" << endl;

    return 0;
}
