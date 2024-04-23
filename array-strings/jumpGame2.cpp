#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int curEnd = 0;
        int curFarthest = 0;
        
        for (int i = 0; i < n - 1; ++i) { // We don't need to consider the last index
            curFarthest = max(curFarthest, i + nums[i]);
            
            if (i == curEnd) { // We reached the current end of jump, update curEnd and increment jumps
                curEnd = curFarthest;
                jumps++;
            }
        }
        
        return jumps;
    }
};