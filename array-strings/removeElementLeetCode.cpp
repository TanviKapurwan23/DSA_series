#include<iostream>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int k = 0; // Counter for non-val elements

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};
int main() {
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    Solution sol;
    int k = sol.removeElement(nums, val);
    
    std::cout << "Output: " << k << ", nums = [";
    for (int i = 0; i < k; i++) {
        std::cout << nums[i];
        if (i < k - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
