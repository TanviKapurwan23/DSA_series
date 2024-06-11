#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), k = s3.length();
        if (m + n != k) return false;

        // Create a 2D DP array dp[m+1][n+1] where dp[i][j] represents if s1[0..i-1] and s2[0..j-1] can interleave to form s3[0..i+j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: Empty strings can always interleave to form an empty string
        dp[0][0] = true;

        // Fill the first row (s1 is empty)
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        // Fill the first column (s2 is empty)
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        // Fill the rest of the DP array
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[m][n];
    }
};
