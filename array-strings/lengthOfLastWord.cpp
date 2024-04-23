#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // Trim leading and trailing whitespace
        int right = s.size() - 1;
        while (right >= 0 && s[right] == ' ') {
            right--;
        }
        
        // Iterate from right to left to find the last word
        int length = 0;
        while (right >= 0 && s[right] != ' ') {
            length++;
            right--;
        }
        
        return length;
    }
};


// We start by trimming any leading and trailing whitespace characters from the string s by iterating from right to left and updating the right index until we encounter a non-whitespace character.
// Then, we iterate from right to left again, counting the number of characters until we encounter a space or reach the beginning of the string.
// The count of characters we encounter during this iteration represents the length of the last word in the string.
// Finally, we return this count as the length of the last word.