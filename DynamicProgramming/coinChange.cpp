class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a vector to store the minimum coins needed for each amount up to 'amount'
        vector<int> dp(amount + 1, amount + 1);  // Initialize with a value larger than any possible result
        dp[0] = 0;  // Base case: No coins are needed to make amount 0

        // Iterate through each amount from 1 to 'amount'
        for (int i = 1; i <= amount; ++i) {
            // Try every coin denomination
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still larger than 'amount', it means we can't form the amount
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
