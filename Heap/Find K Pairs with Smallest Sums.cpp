// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]

#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return result; // Handle edge cases where input arrays are empty or k is invalid
        }

        // Comparator lambda function to compare pairs based on their sums
        auto cmp = [&](const std::vector<int>& a, const std::vector<int>& b) {
            return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]]; // Compare sums of pairs
        };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> minHeap(cmp);

        // Initialize the min heap with pairs from nums1 and nums2[0]
        for (int i = 0; i < std::min(k, static_cast<int>(nums1.size())); ++i) {
            minHeap.push({i, 0});
        }

        // Process k smallest pairs from the min heap
        while (k-- > 0 && !minHeap.empty()) {
            auto pairIdx = minHeap.top(); // Get the top pair from the min heap
            minHeap.pop(); // Remove the top pair from the min heap

            result.push_back({nums1[pairIdx[0]], nums2[pairIdx[1]]}); // Add the pair to the result

            if (pairIdx[1] + 1 < nums2.size()) {
                minHeap.push({pairIdx[0], pairIdx[1] + 1}); // Push the next pair from nums2 into the min heap
            }
        }

        return result; // Return the k smallest pairs
    }
};
