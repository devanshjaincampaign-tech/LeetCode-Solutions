#include <vector>

class Solution {
private:
    int rows, cols;

    void dfs(int r, int c, std::vector<std::vector<int>>& grid) {
        // Out of bounds or water (1)
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark current cell as visited by changing it to water (1)
        grid[r][c] = 1;

        // Traverse in all 4 directions
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        rows = grid.size();
        cols = grid[0].size();

        // Step 1: Eliminate all land (0s) connected to the grid boundaries
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(r, c, grid);
                }
            }
        }

        // Step 2: Count remaining closed islands in the interior
        int closedIslandsCount = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    closedIslandsCount++;
                    dfs(r, c, grid); // Sink the whole island
                }
            }
        }

        return closedIslandsCount;
    }
};