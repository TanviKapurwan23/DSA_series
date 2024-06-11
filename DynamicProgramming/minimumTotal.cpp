class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Special case: If the triangle has only one row, return its element as the minimum total
        if (n == 1) return triangle[0][0];
        
        // Initialize a dp array to store the minimum path sum for each position in the triangle
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];  // Base case: The top of the triangle
        
        // Fill the dp array using the bottom-up approach
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                // Handle the edges of the triangle
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];  // Left edge
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];  // Right edge
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];  // Middle elements
                }
            }
        }
        
        // Find the minimum total sum in the last row of the dp array
        int minTotal = dp[n - 1][0];
        for (int k = 1; k < n; ++k) {
            minTotal = min(minTotal, dp[n - 1][k]);
        }
        
        return minTotal;
    }
};
