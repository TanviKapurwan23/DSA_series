#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row of the transposed matrix
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


// The rotate function takes a matrix represented as a vector of vectors (matrix) and rotates it by 90 degrees clockwise in-place.
// We first transpose the matrix, which involves swapping elements across the diagonal (matrix[i][j] and matrix[j][i]).
// After transposing, we reverse each row of the transposed matrix to achieve the 90-degree clockwise rotation effect.
// The swaps and reversals are done in-place, directly modifying the input matrix without allocating another matrix.
