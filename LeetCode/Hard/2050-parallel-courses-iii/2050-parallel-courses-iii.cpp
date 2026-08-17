

class Solution {
private:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& state, vector<int>& order) {
        state[i] = 1;

        for (int nbr : adj[i]) {
            if (state[nbr] == 1) {
                return false;
            }
            if (state[nbr] == 0) {
                if (!dfs(nbr, adj, state, order)) {
                    return false;
                }
            }
        }

        state[i] = 2;
        order.push_back(i);
        return true;
    }

public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> state(n, 0);
        vector<int> order;

        for (const auto& p : relations) {
            int u = p[0] - 1;
            int v = p[1] - 1;
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                dfs(i, adj, state, order);
            }
        }

        reverse(order.begin(), order.end());

        vector<int> dist(n);
        for (int i = 0; i < n; i++) {
            dist[i] = time[i];
        }

        int ans = 0;
        for (int u : order) {
            ans = max(ans, dist[u]);
            for (int v : adj[u]) {
                dist[v] = max(dist[v], dist[u] + time[v]);
            }
        }

        return ans;
    }
};