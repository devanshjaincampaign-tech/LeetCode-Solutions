#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        std::vector<int> min_len(n, INT_MAX);
        
        int ans = INT_MAX;
        int curr_sum = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            curr_sum += arr[right];
            
            // Shrink window if sum exceeds target
            while (curr_sum > target && left <= right) {
                curr_sum -= arr[left];
                left++;
            }
            
            // Carry forward the previous best length
            if (right > 0) {
                min_len[right] = min_len[right - 1];
            }
            
            // If a valid subarray is found ending at 'right'
            if (curr_sum == target) {
                int curr_len = right - left + 1;
                
                // If a non-overlapping valid subarray exists to the left
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = std::min(ans, curr_len + min_len[left - 1]);
                }
                
                // Update best length seen up to index 'right'
                min_len[right] = std::min(min_len[right], curr_len);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};