class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> ans(k, 0);
        std::vector<long long> dp(k, 0);

        for (int num : nums) {
            std::vector<long long> next_dp(k, 0);
            int num_mod = num % k;

            // Subarray consisting of just the current element
            next_dp[num_mod] += 1;

            // Extend existing subarrays
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_mod = (r * num_mod) % k;
                    next_dp[new_mod] += dp[r];
                }
            }

            // Accumulate counts into overall answer
            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }

            dp = std::move(next_dp);
        }

        return ans;
    }
};