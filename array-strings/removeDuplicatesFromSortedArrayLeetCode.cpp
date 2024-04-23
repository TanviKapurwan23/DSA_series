#include<iostream>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n; // If the array has 2 or fewer elements, no duplicates can exist

        int j = 1;     // Pointer for the current position in the modified array
        int count = 1; // Count of the current element

        for (int i = 1; i < n; ++i)
        {
            // If the current element is equal to the previous element
            if (nums[i] == nums[i - 1])
            {
                // Increment the count
                ++count;
                // If the count is less than or equal to 2, copy the element to the modified array
                if (count <= 2)
                {
                    nums[j++] = nums[i];
                }
            }
            else
            {
                // Reset the count for the new element
                count = 1;
                // Copy the new element to the modified array
                nums[j++] = nums[i];
            }
        }

        // Return the length of the modified array
        return j;
    }
};
int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution sol;
    int k = sol.removeDuplicates(nums);
    
    std::cout << "Output: " << k << ", nums = [";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i];
        if (i < k - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
