#include <iostream>
#include <limits>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int getMinimumDifference(Node* root) {
        int minDiff = numeric_limits<int>::max();
        int prevVal = -1; // Initialize with an invalid value

        inorderTraversal(root, prevVal, minDiff);

        return minDiff;
    }

private:
    void inorderTraversal(Node* root, int& prevVal, int& minDiff) {
        if (!root) return;

        inorderTraversal(root->left, prevVal, minDiff);

        if (prevVal != -1) { // Check if this is not the first node
            minDiff = min(minDiff, root->val - prevVal);
        }
        prevVal = root->val;

        inorderTraversal(root->right, prevVal, minDiff);
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution solution;
    int result = solution.getMinimumDifference(root);
    cout << "Minimum Absolute Difference: " << result << endl;

    // Clean up memory (optional, but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
