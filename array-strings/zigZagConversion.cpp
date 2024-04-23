#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1)
            return s; // If numRows is 1, return the original string

        std::vector<std::string> rows(std::min(numRows, int(s.size()))); // Create numRows rows
        int curRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[curRow] += c; // Append the character to the current row
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;   // Change direction when reaching the top or bottom row
            curRow += goingDown ? 1 : -1; // Move to the next or previous row based on the direction
        }

        std::string result;
        for (const std::string &row : rows)
        {
            result += row; // Concatenate rows to form the result
        }

        return result;
    }
};
int main() {
    std::string s = "PAYPALISHIRING";
    int numRows = 3;
    Solution sol;
    std::string result = sol.convert(s, numRows);
    
    std::cout << "Output: " << result << std::endl;

    return 0;
}

