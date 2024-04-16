#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> zeroRows, zeroCols;

        // Step 1: Find rows and columns containing zeros
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        // Step 2: Set rows containing zeros to all zeros
        for (int row : zeroRows) {
            for (int j = 0; j < n; j++) {
                matrix[row][j] = 0;
            }
        }

        // Step 3: Set columns containing zeros to all zeros
        for (int col : zeroCols) {
            for (int i = 0; i < m; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};


// The setZeroes function takes a matrix represented as a vector of vectors (matrix) and sets rows and columns containing zeros to all zeros in-place.
// We use two unordered sets (zeroRows and zeroCols) to keep track of rows and columns containing zeros.
// In the first pass through the matrix, we populate these sets with the indices of rows and columns containing zeros.
// In the second pass, we set the rows containing zeros to all zeros by iterating through the elements in those rows and setting them to zero.
// Similarly, in the third pass, we set the columns containing zeros to all zeros by iterating through the elements in those columns and setting them to zero.
// The entire process is done in-place, modifying the input matrix directly.