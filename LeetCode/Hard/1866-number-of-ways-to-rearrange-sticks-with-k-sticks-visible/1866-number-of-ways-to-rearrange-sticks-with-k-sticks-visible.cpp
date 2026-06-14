#include <vector>
using namespace std;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        int MOD = 1e9 + 7;
        // dp[j] stores the number of ways to have j visible sticks
        vector<long long> dp(k + 1, 0);
        dp[0] = 1; // Base case: 0 sticks, 0 visible
        
        for (int i = 1; i <= n; ++i) {
            // Traverse backwards to use values from the previous iteration of `i`
            for (int j = min(i, k); j >= 1; --j) {
                dp[j] = (dp[j - 1] + (i - 1) * dp[j]) % MOD;
            }
            dp[0] = 0; // Out of bounds for valid stick configurations when i > 0
        }
        
        return dp[k];
    }
};