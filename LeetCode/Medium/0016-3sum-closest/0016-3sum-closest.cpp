class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        long long greaterclosest = INT_MAX;
        long long lesserclosest = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                
                if (sum == target) return sum;
                
                if (sum > target) {
                    greaterclosest = min((long long)sum, greaterclosest);
                    end--;
                }
                else if (sum < target) {
                    lesserclosest = max((long long)sum, lesserclosest);
                    start++;
                }
            }
        }
        
        if (target - lesserclosest < greaterclosest - target) {
            return lesserclosest;
        }
        return greaterclosest;
    }
};