#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int leftIdx = searchLeft(nums, target);
        int rightIdx = searchRight(nums, target);

        if (leftIdx <= rightIdx) {
            result[0] = leftIdx;
            result[1] = rightIdx;
        }

        return result;
    }

private:
    int searchLeft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }

    int searchRight(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};


// The searchRange function takes a sorted array of integers nums and a target value target and returns the starting and ending positions of the target value.
// We use two helper functions searchLeft and searchRight to find the leftmost and rightmost occurrences of the target, respectively.
// The searchLeft function performs a binary search to find the leftmost occurrence of the target.
// The searchRight function performs a binary search to find the rightmost occurrence of the target.
// If the leftmost and rightmost indices are valid (i.e., leftIdx <= rightIdx), we update the result vector with the starting and ending positions of the target.
// Finally, we return the result vector containing the starting and ending positions of the target, or [-1, -1] if the target is not found.