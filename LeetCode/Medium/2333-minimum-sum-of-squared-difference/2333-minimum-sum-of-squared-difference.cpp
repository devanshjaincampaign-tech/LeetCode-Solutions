#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        std::vector<long long> d(n);
        long long total_diff = 0;
        long long max_val = 0;
        
        for (int i = 0; i < n; ++i) {
            d[i] = std::abs((long long)nums1[i] - nums2[i]);
            total_diff += d[i];
            max_val = std::max(max_val, d[i]);
        }
        
        long long k = (long long)k1 + k2;
        
        // If total operations can reduce all differences to 0
        if (total_diff <= k) {
            return 0;
        }
        
        // Binary search for the optimal maximum difference threshold
        long long left = 0, right = max_val;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long operations_needed = 0;
            for (int i = 0; i < n; ++i) {
                if (d[i] > mid) {
                    operations_needed += (d[i] - mid);
                }
            }
            if (operations_needed <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // Reduce all elements to at most 'left' and update remaining k
        for (int i = 0; i < n; ++i) {
            if (d[i] > left) {
                k -= (d[i] - left);
                d[i] = left;
            }
        }
        
        // Distribute any remaining operations on elements equal to 'left'
        for (int i = 0; i < n; ++i) {
            if (k > 0 && d[i] == left) {
                d[i] -= 1;
                k -= 1;
            }
        }
        
        // Calculate the final sum of squared differences
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += d[i] * d[i];
        }
        
        return ans;
    }
};