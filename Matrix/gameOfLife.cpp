#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Copy the original board to store current state
        vector<vector<int>> nextState(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nextState[i][j] = board[i][j];
            }
        }

        // Apply the rules to update the next state
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = countLiveNeighbors(nextState, i, j);
                if (nextState[i][j] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = 0; // Cell dies due to under-population or over-population
                    }
                } else {
                    if (liveNeighbors == 3) {
                        board[i][j] = 1; // Cell becomes alive due to reproduction
                    }
                }
            }
        }
    }

private:
    int countLiveNeighbors(const vector<vector<int>>& board, int row, int col) {
        int m = board.size();
        int n = board[0].size();
        int liveNeighbors = 0;

        // Define directions for checking neighbors (horizontal, vertical, diagonal)
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int k = 0; k < 8; k++) {
            int newRow = row + dx[k];
            int newCol = col + dy[k];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && board[newRow][newCol] == 1) {
                liveNeighbors++;
            }
        }

        return liveNeighbors;
    }
};

// The gameOfLife function takes a board represented as a vector of vectors (board) and applies the rules of Conway's Game of Life to update the next state.
// We create a copy of the original board (nextState) to store the current state before updating the next state.
// The countLiveNeighbors function calculates the number of live neighbors for a given cell by checking in all eight directions (horizontal, vertical, diagonal).
// We iterate through each cell in the board, count its live neighbors, and update its state based on the rules mentioned in the problem statement.
// The original board (board) is updated in-place to reflect the next state after applying the rules.
// The entire process simulates one generation in Conway's Game of Life.