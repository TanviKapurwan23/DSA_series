#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Mark each number's corresponding index as negative
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        // Collect all the indexes that have positive values
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = solution.findDisappearedNumbers(nums);
    for (int num : result) {
        cout << num << " ";
    }
    // Expected output: 5 6
    return 0;
}
