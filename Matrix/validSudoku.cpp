#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(board, i) || !isValidColumn(board, i) || !isValidSubBox(board, i)) {
                return false;
            }
        }
        return true;
    }

private:
    bool isValidRow(const vector<vector<char>>& board, int row) {
        unordered_set<char> seen;
        for (int col = 0; col < 9; col++) {
            char cell = board[row][col];
            if (cell != '.' && !seen.insert(cell).second) {
                return false; // Duplicate found in row
            }
        }
        return true;
    }

    bool isValidColumn(const vector<vector<char>>& board, int col) {
        unordered_set<char> seen;
        for (int row = 0; row < 9; row++) {
            char cell = board[row][col];
            if (cell != '.' && !seen.insert(cell).second) {
                return false; // Duplicate found in column
            }
        }
        return true;
    }

    bool isValidSubBox(const vector<vector<char>>& board, int box) {
        unordered_set<char> seen;
        int startRow = (box / 3) * 3;
        int startCol = (box % 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                char cell = board[i][j];
                if (cell != '.' && !seen.insert(cell).second) {
                    return false; // Duplicate found in sub-box
                }
            }
        }
        return true;
    }
};


// The isValidSudoku function iterates through each row, column, and 3x3 sub-box of the Sudoku board and checks their validity using helper functions.
// The isValidRow, isValidColumn, and isValidSubBox functions check if each row, column, and sub-box contains digits 1-9 without repetition.
// We use an unordered_set (seen) to track the digits encountered while iterating through each row, column, or sub-box. If a duplicate digit is found (excluding '.' characters), the function returns false, indicating that the Sudoku board is invalid.
// If all rows, columns, and sub-boxes pass the validation checks, the function returns true, indicating that the Sudoku board is valid according to the Sudoku rules.