#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void topView(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Map to store the first node at each horizontal distance
    map<int, int> topViewMap;
    // Queue to store nodes along with their horizontal distance
    queue<pair<Node*, int>> q;

    // Initialize queue with root node at horizontal distance 0
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        // Get the front item from the queue
        pair<Node*, int> p = q.front();
        q.pop();

        Node* node = p.first;
        int hd = p.second;

        // If this is the first node at this horizontal distance, add it to the map
        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->data;
        }

        // Enqueue the left child with horizontal distance - 1
        if (node->left != nullptr) {
            q.push(make_pair(node->left, hd - 1));
        }

        // Enqueue the right child with horizontal distance + 1
        if (node->right != nullptr) {
            q.push(make_pair(node->right, hd + 1));
        }
    }

    // Print the top view
    for (auto it : topViewMap) {
        cout << it.second << " ";
    }
}

int main() {
    // Creating a simple tree:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Top view: ";
    topView(root); // Output should be the top view of the tree

    return 0;
}
