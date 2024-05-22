// Merge Strings Alternately
/*
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
*/

#include <iostream>
#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string result;
        int i = 0, j = 0;
        int n1 = word1.size(), n2 = word2.size();
        
        // Merge characters alternately from both strings
        while (i < n1 || j < n2) {
            if (i < n1) {
                result += word1[i++];
            }
            if (j < n2) {
                result += word2[j++];
            }
        }
        
        return result;
    }
};

int main() {
    std::string word1, word2;
    
    // Take input from user
    std::cout << "Enter the first word: ";
    std::cin >> word1;
    std::cout << "Enter the second word: ";
    std::cin >> word2;
    
    // Create an instance of Solution and merge the strings
    Solution solution;
    std::string mergedString = solution.mergeAlternately(word1, word2);
    
    // Print the result
    std::cout << "Merged string: " << mergedString << std::endl;
    
    return 0;
}
