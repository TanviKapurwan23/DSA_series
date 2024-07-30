#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sortedNums = nums; // Copy the original array
        sort(sortedNums.begin(), sortedNums.end()); // Sort the copied array

        unordered_map<int, int> numToCount; // Map to store the count of smaller numbers for each number
        for (int i = 0; i < sortedNums.size(); i++) {
            if (numToCount.find(sortedNums[i]) == numToCount.end()) {
                numToCount[sortedNums[i]] = i; // Store the smallest index of each number
            }
        }

        vector<int> result;
        for (int num : nums) {
            result.push_back(numToCount[num]); // Get the count of smaller numbers for each number
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> result = solution.smallerNumbersThanCurrent(nums);
    for (int count : result) {
        cout << count << " ";
    }
    // Expected output: 4 0 1 1 3
    return 0;
}
