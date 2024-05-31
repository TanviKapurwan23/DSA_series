#include <iostream>
#include <vector>
using namespace std;

vector<string> cavityMap(vector<string> grid) {
    int n = grid.size();

    // Iterate through the grid (excluding border elements)
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            // Check if current element is a cavity
            if (grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i + 1][j] &&
                grid[i][j] > grid[i][j - 1] && grid[i][j] > grid[i][j + 1]) {
                // Mark the cavity by replacing its value with 'X'
                grid[i][j] = 'X';
            }
        }
    }

    return grid;
}

int main() {
    vector<string> grid = {"1112", "1912", "1892", "1234"};

    grid = cavityMap(grid);
    for (const string& row : grid) {
        cout << row << endl;
    }

    return 0;
}
