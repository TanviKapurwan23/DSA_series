#include <string>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> numStack; // Stack to store numbers and intermediate results
        int num = 0; // Current number being processed
        char sign = '+'; // Current operator (+, -, *, /)

        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i]; // Current character in the input string

            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // Build the current number
            }

            if (c == '(') {
                // Find the matching closing parenthesis
                int j = i + 1;
                int count = 1;
                while (j < s.size()) {
                    if (s[j] == '(') {
                        count++;
                    } else if (s[j] == ')') {
                        count--;
                        if (count == 0) break; // Matching closing parenthesis found
                    }
                    j++;
                }
                // Evaluate the expression within the parentheses recursively
                num = calculate(s.substr(i + 1, j - i - 1));
                i = j; // Move the index to the end of the evaluated expression
            }

            // Process operators and end of expression
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (sign == '+') {
                    numStack.push(num);
                } else if (sign == '-') {
                    numStack.push(-num);
                } else if (sign == '*') {
                    int top = numStack.top();
                    numStack.pop();
                    numStack.push(top * num);
                } else if (sign == '/') {
                    int top = numStack.top();
                    numStack.pop();
                    numStack.push(top / num);
                }

                sign = c; // Update the current operator
                num = 0; // Reset the current number
            }
        }

        // Calculate the final result by summing up all elements in numStack
        int result = 0;
        while (!numStack.empty()) {
            result += numStack.top();
            numStack.pop();
        }

        return result;
    }
};
