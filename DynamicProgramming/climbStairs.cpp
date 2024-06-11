class Solution {
public:
    int climbStairs(int n) {
        // If there are no steps or just one step, there's only one way to climb the stairs
        if (n == 0 || n == 1) {
            return 1;
        }
        
        // Create a vector to store the number of ways to climb to each step
        std::vector<int> dp(n + 1);
        
        // Base cases
        dp[0] = 1; // One way to stay at the ground (do nothing)
        dp[1] = 1; // One way to reach the first step
        
        // Fill the dp array using the bottom-up approach
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};
