// 1. Brute Force Approach
// This approach checks every possible path in the tree by starting from each node and considering all paths starting from that node.


class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return pathSumFrom(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    
private:
    int pathSumFrom(TreeNode* node, int sum) {
        if (!node) return 0;
        return (node->val == sum ? 1 : 0) +
               pathSumFrom(node->left, sum - node->val) +
               pathSumFrom(node->right, sum - node->val);
    }
};
// 2. Optimized Approach Using Prefix Sum
// This approach uses a hash map to store the prefix sum and reduces the complexity to O(N).


#include <unordered_map>

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // Base case to handle exact targetSum path
        return dfs(root, 0, targetSum, prefixSumCount);
    }
    
private:
    int dfs(TreeNode* node, int currSum, int targetSum, unordered_map<int, int>& prefixSumCount) {
        if (!node) return 0;
        
        currSum += node->val;
        int numPathsToCurr = prefixSumCount[currSum - targetSum];
        
        prefixSumCount[currSum]++;
        
        int result = numPathsToCurr + dfs(node->left, currSum, targetSum, prefixSumCount) + dfs(node->right, currSum, targetSum, prefixSumCount);
        
        prefixSumCount[currSum]--;  // Remove the current node's value to backtrack
        
        return result;
    }
};
// 3. Using a Helper Function to Count Paths
// This approach uses a helper function to count paths starting from each node.


class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        return countPaths(root, targetSum);
    }

private:
    int countPaths(TreeNode* node, int targetSum) {
        if (!node) return 0;
        
        return pathsFromNode(node, targetSum) +
               countPaths(node->left, targetSum) +
               countPaths(node->right, targetSum);
    }
    
    int pathsFromNode(TreeNode* node, int targetSum) {
        if (!node) return 0;
        
        return (node->val == targetSum ? 1 : 0) +
               pathsFromNode(node->left, targetSum - node->val) +
               pathsFromNode(node->right, targetSum - node->val);
    }
};
// 4. Combining DFS and Hash Map for Prefix Sum
// A more optimized solution by combining depth-first search (DFS) and hash map to handle the prefix sums efficiently.

#include <unordered_map>

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSum;
        prefixSum[0] = 1;  // Base case to handle exact targetSum path
        return dfs(root, 0, targetSum, prefixSum);
    }

private:
    int dfs(TreeNode* node, long currSum, int targetSum, unordered_map<long, int>& prefixSum) {
        if (!node) return 0;
        
        currSum += node->val;
        int res = prefixSum[currSum - targetSum];
        
        prefixSum[currSum]++;
        
        res += dfs(node->left, currSum, targetSum, prefixSum) + dfs(node->right, currSum, targetSum, prefixSum);
        
        prefixSum[currSum]--;  // Remove the current node's value to backtrack
        
        return res;
    }
};
