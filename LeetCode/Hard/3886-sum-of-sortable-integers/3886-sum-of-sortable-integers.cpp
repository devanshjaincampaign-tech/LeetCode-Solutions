#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            
            bool ok = true;
            for (int i = 0; i < n; i += k) {
                int drops = 0;
                int split_idx = 0;
                for (int j = 0; j < k; ++j) {
                    if (nums[i + j] > nums[i + (j + 1) % k]) {
                        drops++;
                        split_idx = (j + 1) % k;
                    }
                }
                
                if (drops > 1) {
                    ok = false;
                    break;
                }
                
                for (int j = 0; j < k; ++j) {
                    if (nums[i + (split_idx + j) % k] != sorted_nums[i + j]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                totalSum += k;
            }
        }
        return totalSum;
    }
};