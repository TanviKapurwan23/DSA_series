#include<iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // Normalize k to be within the range of 0 to n-1

        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    Solution sol;
    sol.rotate(nums1, k1);
    
    std::cout << "Output 1: [";
    for (int i = 0; i < nums1.size(); ++i) {
        std::cout << nums1[i];
        if (i < nums1.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    std::vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    sol.rotate(nums2, k2);
    
    std::cout << "Output 2: [";
    for (int i = 0; i < nums2.size(); ++i) {
        std::cout << nums2[i];
        if (i < nums2.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
