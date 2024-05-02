#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 1); // Initialize the row with 1s

        for (int i = 1; i < rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                row[j] += row[j - 1]; // Calculate the next row element using combinations formula
            }
        }

        return row;
    }
};

int main() {
    Solution solution;
    int rowIndex = 3;
    std::vector<int> result = solution.getRow(rowIndex);

    std::cout << "Row " << rowIndex << " of Pascal's Triangle: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
