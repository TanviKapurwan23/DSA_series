#include<iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = 0; // Initialize the candidate element
        int count = 0; // Initialize the count of the candidate element
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (candidate == num) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution sol;
    int majority = sol.majorityElement(nums);
    
    std::cout << "Majority Element: " << majority << std::endl;

    return 0;
}
