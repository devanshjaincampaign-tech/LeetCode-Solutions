class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixsum(n, 0);
        prefixsum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + nums[i];
        }

        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]);
            int subSum = prefixsum[i] - (start > 0 ? prefixsum[start - 1] : 0);
            totalsum += subSum;
        }

        return totalsum;
    }
};