#include <vector>
#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> operandStack;

        for (const std::string& token : tokens) {
            if (isOperator(token)) {
                int operand2 = operandStack.top();
                operandStack.pop();
                int operand1 = operandStack.top();
                operandStack.pop();

                int result = performOperation(operand1, operand2, token);
                operandStack.push(result);
            } else {
                operandStack.push(std::stoi(token));
            }
        }

        return operandStack.top();
    }

private:
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int performOperation(int operand1, int operand2, const std::string& op) {
        if (op == "+") {
            return operand1 + operand2;
        } else if (op == "-") {
            return operand1 - operand2;
        } else if (op == "*") {
            return operand1 * operand2;
        } else if (op == "/") {
            return operand1 / operand2; // Division truncates toward zero
        }
        return 0; // Invalid operator
    }
};

int main() {
    Solution solution;
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    int result = solution.evalRPN(tokens);
    std::cout << "Output: " << result << std::endl;
    return 0;
}
