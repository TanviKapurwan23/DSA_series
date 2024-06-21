// Using a Heap (Priority Queue)

#include <queue>
#include <vector>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        inorder(root, minHeap);

        while (k > 1) {
            minHeap.pop();
            k--;
        }
        return minHeap.top();
    }

private:
    void inorder(TreeNode* node, std::priority_queue<int, std::vector<int>, std::greater<int>>& minHeap) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, minHeap);
        minHeap.push(node->val);
        inorder(node->right, minHeap);
    }
};
