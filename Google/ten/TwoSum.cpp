#include <vector>
#include<iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash; // Create a hash table to store numbers and their indices

        // Iterate through each element in the nums array
        for (int i = 0; i < nums.size(); ++i) {
            int x = target - nums[i];   // Calculate the complement x needed to reach the target

            // Check if the complement x exists in the hash table
            if (hash.find(x) != hash.end()) {
                // If found, return the indices of the complement and the current number
                return {hash[x], i};
            }

            // If the complement is not found, insert the current number and its index into the hash table
            hash[nums[i]] = i;
        }

        // If no solution is found, return an empty vector
        return {};
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    for (int index : result) {
        cout << index << " ";
    }
    return 0;
}
