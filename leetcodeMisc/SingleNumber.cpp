#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0; // Variable to hold the XOR of all elements
        
        // Iterate through the elements of the array
        for (int num : nums) {
            result ^= num; // Perform XOR with each element
        }
        
        return result; // Return the unique element
    }
};
