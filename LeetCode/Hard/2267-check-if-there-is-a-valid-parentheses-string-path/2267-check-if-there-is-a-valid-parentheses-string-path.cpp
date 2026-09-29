class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // A valid path must have an even length (m + n - 1 must be even)
        // and must start with '(' and end with ')'
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        // dp[r][c][bal] indicates if balance 'bal' is reachable at cell (r, c)
        bool dp[100][100][101] = {false};
        
        dp[0][0][1] = true;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int bal = 0; bal <= (m + n) / 2; ++bal) {
                    if (!dp[r][c][bal]) continue;

                    // Move Down
                    if (r + 1 < m) {
                        int next_bal = bal + (grid[r + 1][c] == '(' ? 1 : -1);
                        if (next_bal >= 0) {
                            dp[r + 1][c][next_bal] = true;
                        }
                    }

                    // Move Right
                    if (c + 1 < n) {
                        int next_bal = bal + (grid[r][c + 1] == '(' ? 1 : -1);
                        if (next_bal >= 0) {
                            dp[r][c + 1][next_bal] = true;
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};