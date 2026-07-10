class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int LOG = 18;
        
        // 1. Sort elements by value while preserving original index
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());
        
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[sorted_nodes[i].second] = i;
        }
        
        // 2. Initialize the sparse table for binary lifting
        vector<vector<int>> st(n, vector<int>(LOG, 0));
        int r = 0;
        for (int i = 0; i < n; ++i) {
            if (r < i) r = i;
            while (r + 1 < n && sorted_nodes[r + 1].first - sorted_nodes[i].first <= maxDiff) {
                r++;
            }
            st[i][0] = r;
        }
        
        // 3. Populate binary lifting rows
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                st[i][j] = st[st[i][j - 1]][j - 1];
            }
        }
        
        // 4. Resolve queries
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& query : queries) {
            int a = pos[query[0]];
            int b = pos[query[1]];
            if (a > b) swap(a, b);
            
            if (a == b) {
                ans.push_back(0);
                continue;
            }
            
            int steps = 0;
            for (int j = LOG - 1; j >= 0; --j) {
                if (st[a][j] < b) {
                    steps += (1 << j);
                    a = st[a][j];
                }
            }
            
            if (st[a][0] >= b) {
                ans.push_back(steps + 1);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};