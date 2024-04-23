#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (i > furthest) { // Current index is beyond furthest reachable position
                return false;
            }
            
            furthest = max(furthest, i + nums[i]); // Update furthest reachable position
            if (furthest >= n - 1) { // If we can reach the end, return true
                return true;
            }
        }
        
        return false; // Couldn't reach the end
    }
};


// use a greedy approach. You start from the first index and keep track of the furthest position you can reach from there.
