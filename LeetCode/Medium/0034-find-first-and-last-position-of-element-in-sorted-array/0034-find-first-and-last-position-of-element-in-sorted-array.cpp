class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=INT_MAX;
        int end=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                start=min(start,i);
                end=max(end,i);
            }
        }
        if(start==INT_MAX && end==INT_MIN){
            return {-1,-1};
        }

        return {start,end};
    }
};