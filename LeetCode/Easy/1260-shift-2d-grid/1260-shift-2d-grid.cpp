class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        vector<int> vp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vp.push_back(grid[i][j]);
            }
        }

        k = k % total;

        while (k > 0) {
            int last = vp[total - 1];
            for (int i = total - 1; i > 0; i--) {
                vp[i] = vp[i - 1];
            }
            vp[0] = last;
            k--;
        }

        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = vp[idx++];
            }
        }

        return grid;
    }
};