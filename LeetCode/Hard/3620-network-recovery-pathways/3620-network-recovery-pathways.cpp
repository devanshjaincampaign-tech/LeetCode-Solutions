#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int num_nodes;
    vector<vector<pair<int, int>>> adj;
    vector<long long> memo;
    const long long INF = 1e18; // Large enough infinity boundary safely greater than max k

    // Memoized DFS to find the minimum cost to reach node (n-1) from node u
    long long getMinCost(int u, int min_edge_val, const vector<bool>& online) {
        // Destination reached
        if (u == num_nodes - 1) return 0;
        if (memo[u] != -1) return memo[u];

        long long min_cost = INF;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int cost = edge.second;

            // Only proceed if the edge value satisfies our target binary search threshold 
            // and the next destination node is online
            if (cost >= min_edge_val && online[v]) {
                long long sub_path = getMinCost(v, min_edge_val, online);
                if (sub_path != INF) {
                    min_cost = min(min_cost, sub_path + cost);
                }
            }
        }

        return memo[u] = min_cost;
    }

    bool isValid(int target_score, const vector<bool>& online, long long k) {
        // Reset memo array for the current binary search validation check
        memo.assign(num_nodes, -1);
        return getMinCost(0, target_score, online) <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        num_nodes = online.size();
        adj.resize(num_nodes);
        
        int max_edge_cost = 0;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({v, cost});
            max_edge_cost = max(max_edge_cost, cost);
        }

        // Binary search for the maximum bottleneck edge value
        int low = 0, high = max_edge_cost;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(mid, online, k)) {
                result = mid;    // This bottleneck score is achievable, try higher values
                low = mid + 1;
            } else {
                high = mid - 1;  // Not achievable, lower our threshold requirement
            }
        }

        return result;
    }
};