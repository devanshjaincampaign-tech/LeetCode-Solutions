class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        if (nums.empty()) return 0; 
        
        long long maxval = nums[0];
        long long minval = nums[0];
        
        for (int i : nums) {
            if (i > maxval) maxval = i;
            if (i < minval) minval = i;
        }
        
        return (maxval - minval) * k;
    }
};