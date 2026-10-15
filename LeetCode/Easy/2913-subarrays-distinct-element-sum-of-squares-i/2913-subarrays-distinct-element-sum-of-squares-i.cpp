class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<int> distinct;
            for (int j = i; j < n; ++j) {
                distinct.insert(nums[j]);
                int count = distinct.size();
                total += count * count;
            }
        }
        return total;
    }
};