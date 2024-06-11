class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns
        
        // Initialize a dp array to store the minimum path sum for each position in the grid
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize the top-left cell with its value
        dp[0][0] = grid[0][0];
        
        // Fill the dp array using the bottom-up approach
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0]; // Fill the first column
        }
        
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j]; // Fill the first row
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]; // Choose the minimum path
            }
        }
        
        // Return the minimum path sum at the bottom-right corner
        return dp[m - 1][n - 1];
    }
};
