class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSide = 0;

        // Fill the first row and first column of dp
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            maxSide = max(maxSide, dp[i][0]);
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            maxSide = max(maxSide, dp[0][j]);
        }

        // Fill the rest of the dp array
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide * maxSide; // Return the area of the largest square
    }
};
