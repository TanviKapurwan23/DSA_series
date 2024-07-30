#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    // Start DFS from the first land cell found
                    return dfs(grid, i, j);
                }
            }
        }
        
        return 0; // No land found
    }
    
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // If out of bounds or water, contribute to the perimeter
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
            return 1;
        }
        
        // If already visited, no contribution
        if (grid[i][j] == -1) {
            return 0;
        }
        
        // Mark the cell as visited
        grid[i][j] = -1;
        
        int perimeter = 0;
        
        // Visit all 4 adjacent cells
        perimeter += dfs(grid, i - 1, j); // Top
        perimeter += dfs(grid, i + 1, j); // Bottom
        perimeter += dfs(grid, i, j - 1); // Left
        perimeter += dfs(grid, i, j + 1); // Right
        
        return perimeter;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    int result = solution.islandPerimeter(grid);
    printf("The perimeter of the island is: %d\n", result);

    return 0;
}
