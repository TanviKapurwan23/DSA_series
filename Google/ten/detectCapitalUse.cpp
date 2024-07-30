#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1) return true; // A single letter is always correctly capitalized

        // Case 1: All letters are capitals
        if (isupper(word[0]) && isupper(word[1])) {
            for (int i = 2; i < n; i++) {
                if (islower(word[i])) return false;
            }
            return true;
        }
        
        // Case 2: All letters are not capitals or only the first letter is capital
        for (int i = 1; i < n; i++) {
            if (isupper(word[i])) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    // Test cases
    cout << solution.detectCapitalUse("USA") << endl;       // Expected output: 1 (true)
    cout << solution.detectCapitalUse("leetcode") << endl;  // Expected output: 1 (true)
    cout << solution.detectCapitalUse("Google") << endl;    // Expected output: 1 (true)
    cout << solution.detectCapitalUse("FlaG") << endl;      // Expected output: 0 (false)
    return 0;
}
