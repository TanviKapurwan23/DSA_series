#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charCount;
        
        // First pass: count the frequency of each character
        for (char c : s) {
            charCount[c]++;
        }
        
        // Second pass: find the first character with a frequency of 1
        for (int i = 0; i < s.size(); i++) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }
        
        return -1; // If there is no non-repeating character
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    int result = solution.firstUniqChar(s);
    cout << result << endl; // Expected output: 0 (index of 'l')
    
    s = "loveleetcode";
    result = solution.firstUniqChar(s);
    cout << result << endl; // Expected output: 2 (index of 'v')
    
    s = "aabb";
    result = solution.firstUniqChar(s);
    cout << result << endl; // Expected output: -1 (no unique character)
    
    return 0;
}
