#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numToIndex; // Map to store number-index pairs
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i]; // Calculate the complement of the current number
            
            // Check if the complement exists in the map
            if (numToIndex.find(complement) != numToIndex.end()) {
                // Return the indices of the two numbers that add up to the target
                return {numToIndex[complement], i};
            }
            
            // Add the current number and its index to the map
            numToIndex[nums[i]] = i;
        }
        
        // Return an empty vector if no solution is found (shouldn't happen per problem constraints)
        return {};
    }
};
