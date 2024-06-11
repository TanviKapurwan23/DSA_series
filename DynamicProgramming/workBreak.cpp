class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Base case: an empty string can always be segmented

        // Iterate through each character in the string
        for (int i = 1; i <= n; ++i) {
            // Check all substrings ending at position i
            for (int j = 0; j < i; ++j) {
                // If the substring s[j:i] is in the dictionary and dp[j] is true, set dp[i] to true
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        // The answer is whether the entire string can be segmented
        return dp[n];
    }
};
