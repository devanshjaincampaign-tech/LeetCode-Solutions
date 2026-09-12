class Solution {
    struct Interval {
        long long l, r, weight;
        int id;
    };

    struct State {
        long long weight = -1;
        vector<int> ids;
    };

    // Returns true if candidate 'a' is strictly better than 'b'
    bool isBetter(const State& a, const State& b) {
        if (a.weight != b.weight) {
            return a.weight > b.weight;
        }
        return a.ids < b.ids;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort intervals by right boundary ascending
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.r != b.r) return a.r < b.r;
            return a.l < b.l;
        });

        // Precompute right endpoints for binary searching non-overlapping intervals
        vector<long long> r_vals(n);
        for (int i = 0; i < n; ++i) {
            r_vals[i] = arr[i].r;
        }

        // dp[i][k]: Best state using a subset of first i intervals picking exactly k intervals
        vector<array<State, 5>> dp(n + 1);

        for (int i = 0; i < n; ++i) {
            // Find rightmost interval j such that arr[j].r < arr[i].l
            auto it = lower_bound(r_vals.begin(), r_vals.begin() + i, arr[i].l);
            int p = distance(r_vals.begin(), it) - 1; // index in arr, or -1 if none

            for (int k = 1; k <= 4; ++k) {
                // Option 1: Do not include arr[i]
                dp[i + 1][k] = dp[i][k];

                // Option 2: Include arr[i]
                State take;
                if (k == 1) {
                    take.weight = arr[i].weight;
                    take.ids = {arr[i].id};
                } else if (p >= 0 && dp[p + 1][k - 1].weight != -1) {
                    take.weight = dp[p + 1][k - 1].weight + arr[i].weight;
                    take.ids = dp[p + 1][k - 1].ids;
                    
                    // Insert arr[i].id in sorted position
                    auto pos = lower_bound(take.ids.begin(), take.ids.end(), arr[i].id);
                    take.ids.insert(pos, arr[i].id);
                }

                if (take.weight != -1 && isBetter(take, dp[i + 1][k])) {
                    dp[i + 1][k] = std::move(take);
                }
            }
        }

        // Find the best across all k in [1, 4]
        State best;
        for (int k = 1; k <= 4; ++k) {
            if (dp[n][k].weight != -1 && isBetter(dp[n][k], best)) {
                best = dp[n][k];
            }
        }

        return best.ids;
    }
};