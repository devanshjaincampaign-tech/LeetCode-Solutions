class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countPairsLessThanOrEqualTo(nums, upper) - countPairsLessThanOrEqualTo(nums, lower - 1);
    }

private:
    long long countPairsLessThanOrEqualTo(const vector<int>& nums, int target) {
        long long count = 0;
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            if (nums[left] + nums[right] <= target) {
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};