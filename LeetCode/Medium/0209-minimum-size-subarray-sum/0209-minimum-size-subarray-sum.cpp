class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int mindistance = INT_MAX; 
        int current_sum = 0; 

        for(int right = 0; right < nums.size(); right++){
            current_sum += nums[right]; 
            
            while(current_sum >= target){
                mindistance = min(mindistance, right - left + 1); 
                current_sum -= nums[left]; 
                left++;
            }
        }
        
        return (mindistance == INT_MAX) ? 0 : mindistance;
    }
};