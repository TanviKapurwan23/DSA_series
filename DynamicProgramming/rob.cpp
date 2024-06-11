class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Create a dp array to store the maximum amount of money that can be robbed up to each house
        vector<int> dp(n, 0);
        
        // Initialize the first two values
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        // Fill the dp array using the bottom-up approach
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        // The last element in the dp array contains the maximum amount of money that can be robbed
        return dp[n - 1];
    }
};
