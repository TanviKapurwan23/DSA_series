#include <string>
#include <sstream> // For stringstream
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Trim leading and trailing whitespace
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;
        s = s.substr(left, right - left + 1);
        
        // Reverse the entire string
        reverse(s.begin(), s.end());
        
        // Reverse each word individually and remove extra spaces
        stringstream ss(s);
        string word, reversed;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            reversed += word + " ";
        }
        
        // Remove trailing space if any
        if (!reversed.empty()) {
            reversed.pop_back();
        }
        
        return reversed;
    }
};
