class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_r = -1, start_c = -1;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        int litter_count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litter_count++;
                }
            }
        }
        
        // Edge case: No litter to collect
        if (litter_count == 0) return 0;
        
        int target_mask = (1 << litter_count) - 1;
        
        // max_energy[r][c][mask] stores the maximum remaining energy seen
        vector<vector<vector<int>>> max_energy(
            m, vector<vector<int>>(n, vector<int>(1 << litter_count, -1))
        );
        
        // queue stores: {row, col, current_energy, mask, moves}
        queue<tuple<int, int, int, int, int>> q;
        q.push({start_r, start_c, energy, 0, 0});
        max_energy[start_r][start_c][0] = energy;
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c, cur_e, mask, moves] = q.front();
            q.pop();
            
            if (cur_e == 0) continue; // Cannot make any more moves
            
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (classroom[nr][nc] == 'X') continue;
                
                int next_e = (classroom[nr][nc] == 'R') ? energy : cur_e - 1;
                int next_mask = mask;
                
                if (classroom[nr][nc] == 'L') {
                    next_mask |= (1 << litter_id[nr][nc]);
                }
                
                if (next_mask == target_mask) {
                    return moves + 1;
                }
                
                if (next_e > max_energy[nr][nc][next_mask]) {
                    max_energy[nr][nc][next_mask] = next_e;
                    q.push({nr, nc, next_e, next_mask, moves + 1});
                }
            }
        }
        
        return -1;
    }
};