#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            int currentValue = romanValues[s[i]];
            if (i < s.size() - 1 && currentValue < romanValues[s[i + 1]]) {
                result -= currentValue; // Subtract if the current value is smaller than the next value
            } else {
                result += currentValue; // Add if the current value is equal to or greater than the next value
            }
        }
        
        return result;
    }
};
