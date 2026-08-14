class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (const auto& p : edges) {
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        int remainingNodes = n;

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        while (remainingNodes > 2) {
            int leafCount = q.size();
            remainingNodes -= leafCount;

            for (int i = 0; i < leafCount; i++) {
                int leaf = q.front();
                q.pop();

                for (int neighbour : adj[leaf]) {
                    degree[neighbour]--;
                    if (degree[neighbour] == 1) {
                        q.push(neighbour);
                    }
                }
            }
        }

        vector<int> answer;
        while (!q.empty()) {
            answer.push_back(q.front());
            q.pop();
        }

        return answer;
    }
};