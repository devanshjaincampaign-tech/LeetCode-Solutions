class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxvalue = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Cast to long long to prevent 32-bit integer overflow
                    long long currentvalue = (long long)(nums[i] - nums[j]) * nums[k];
                    maxvalue = max(currentvalue, maxvalue);
                }
            }
        }
        
        return maxvalue; 
    }
};