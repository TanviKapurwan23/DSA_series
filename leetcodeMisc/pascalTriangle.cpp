#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle; // Vector to store the triangle
        
        if (numRows <= 0) {
            return triangle; // Return empty triangle for non-positive numRows
        }
        
        // Initialize the first row of the triangle with a single element 1
        triangle.push_back({1});
        
        // Iterate to generate each row of the triangle
        for (int i = 1; i < numRows; ++i) {
            std::vector<int> row(i + 1, 1); // Initialize the row with 1s
            
            // Calculate the elements of the current row based on the previous row
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            triangle.push_back(row); // Add the row to the triangle
        }
        
        return triangle;
    }
};
