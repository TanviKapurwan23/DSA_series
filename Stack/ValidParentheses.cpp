#include <iostream> 
#include <stack>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        // Mapping of closing brackets to their corresponding opening brackets
        std::unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        // Stack to keep track of opening brackets
        std::stack<char> bracketStack;

        // Iterate through each character in the string
        for (char c : s) {
            // If c is an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                bracketStack.push(c);
            } else {
                // If c is a closing bracket
                // Check if the stack is empty or if the corresponding opening bracket doesn't match
                if (bracketStack.empty() || bracketStack.top() != bracketMap[c]) {
                    return false; // Invalid string
                }
                bracketStack.pop(); // Pop the matching opening bracket
            }
        }

        // If the stack is empty after processing the string, it's valid
        return bracketStack.empty();
    }
};
int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test cases
    std::string input1 = "()";
    std::string input2 = "()[]{}";
    std::string input3 = "(]";
    
    // Check validity of each input string
    bool result1 = solution.isValid(input1);
    bool result2 = solution.isValid(input2);
    bool result3 = solution.isValid(input3);

    // Output the results
    std::cout << "Input 1 is " << (result1 ? "valid" : "invalid") << std::endl;
    std::cout << "Input 2 is " << (result2 ? "valid" : "invalid") << std::endl;
    std::cout << "Input 3 is " << (result3 ? "valid" : "invalid") << std::endl;

    return 0;
}

// uses a stack to keep track of opening brackets encountered in the string. It also utilizes an unordered map to map closing brackets to their corresponding opening brackets, making it easy to check for validity while iterating through the string.





