#include <vector>
#include <iostream>
#include <algorithm> // For max function

using namespace std;

int maxSubarray(vector<int>& nums) {
    if (nums.empty()) return 0; // Handle empty array case

    int maxSum = nums[0]; // Initialize maxSum with the first element
    int currentSum = nums[0]; // Initialize currentSum with the first element

    for (int i = 1; i < nums.size(); ++i) {
        currentSum = max(nums[i], currentSum + nums[i]); // Update currentSum
        maxSum = max(maxSum, currentSum); // Update maxSum
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubarray(nums);

    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}
