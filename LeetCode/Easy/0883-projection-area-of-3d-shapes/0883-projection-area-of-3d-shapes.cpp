
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int xy = 0;
        int yz = 0;
        int zx = 0;

        for (int i = 0; i < n; i++) {
            int maxRow = 0;
            int maxCol = 0;
            
            for (int j = 0; j < n; j++) {
                // XY Projection: Count every cell that has at least one cube
                if (grid[i][j] > 0) {
                    xy++;
                }
                
                // Track max in the current row (for ZX projection)
                maxRow = max(maxRow, grid[i][j]);
                
                // Track max in the current column (for YZ projection)
                maxCol = max(maxCol, grid[j][i]);
            }
            
            zx += maxRow;
            yz += maxCol;
        }

        return xy + yz + zx;
    }
};