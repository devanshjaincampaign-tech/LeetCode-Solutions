class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefixsum(n, 0);
        vector<int> suffixsum(n, 0);

        prefixsum[0] = nums[0];
        suffixsum[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + nums[i];
        }   

        for (int i = n - 2; i >= 0; i--) {
            suffixsum[i] = suffixsum[i + 1] + nums[i];
        }

        int partition = 0;

        for (int i = 0; i < n - 1; i++) {
            if ((prefixsum[i] - suffixsum[i + 1]) % 2 == 0) {
                partition++;
            }
        }

        return partition;
    }
};