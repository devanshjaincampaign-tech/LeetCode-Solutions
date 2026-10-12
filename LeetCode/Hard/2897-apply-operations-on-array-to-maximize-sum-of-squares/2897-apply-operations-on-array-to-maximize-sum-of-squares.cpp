class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        std::vector<int> cnt(31, 0);
        
        for (int x : nums) {
            for (int i = 0; i <= 30; ++i) {
                if ((x >> i) & 1) {
                    cnt[i]++;
                }
            }
        }
        
        long long ans = 0;
        
        for (int step = 0; step < k; ++step) {
            long long curr = 0;
            for (int i = 30; i >= 0; --i) {
                if (cnt[i] > 0) {
                    curr |= (1LL << i);
                    cnt[i]--;
                }
            }
            ans = (ans + (curr * curr) % MOD) % MOD;
        }
        
        return ans;
    }
};