class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> net_trust(n + 1, 0);
        
        for (const auto& relationship : trust) {
            net_trust[relationship[0]]--; // Out-degree
            net_trust[relationship[1]]++; // In-degree
        }
        
        for (int i = 1; i <= n; i++) {
            if (net_trust[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};