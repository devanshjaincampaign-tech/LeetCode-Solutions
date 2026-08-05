class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> is_suspicious(n, false);
        queue<int> q;

        q.push(k);
        is_suspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!is_suspicious[neighbor]) {
                    is_suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];

            if (!is_suspicious[u] && is_suspicious[v]) {
                vector<int> all_methods(n);
                for (int i = 0; i < n; ++i) {
                    all_methods[i] = i;
                }
                return all_methods;
            }
        }

        vector<int> remaining;
        for (int i = 0; i < n; ++i) {
            if (!is_suspicious[i]) {
                remaining.push_back(i);
            }
        }

        return remaining;
    }
};