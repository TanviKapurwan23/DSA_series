#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if (matrix.empty() || matrix[0].empty()) {
            return result; // Return empty result if matrix is empty
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

        while (top <= bottom && left <= right) {
            // Traverse top row
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++; // Move to next row

            // Traverse right column
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move to previous column

            if (top <= bottom) {
                // Traverse bottom row
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--; // Move to previous row
            }

            if (left <= right) {
                // Traverse left column
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move to next column
            }
        }

        return result;
    }
};


// The spiralOrder function takes a matrix represented as a vector of vectors (matrix) and returns a vector containing the elements of the matrix in spiral order.
// We initialize the result vector to store the elements in spiral order.
// The algorithm uses four variables (top, bottom, left, right) to track the boundaries of the spiral traversal.
// We traverse the matrix in a spiral order, starting with the top row and moving clockwise until we cover all elements.
// In each iteration, we traverse one row or column and update the boundaries accordingly.
// The traversal continues as long as the top boundary is less than or equal to the bottom boundary, and the left boundary is less than or equal to the right boundary.
// The result vector contains all elements of the matrix in spiral order after the traversal is complete.