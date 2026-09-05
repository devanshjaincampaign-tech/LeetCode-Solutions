class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size()-1;
        vector<int>prefixsum(nums.size(),0);
        vector<int>suffixsum(nums.size(),0);

        prefixsum[0]=nums[0];
        suffixsum[n]=nums[n];

        for(int i=1;i<nums.size();i++){
            prefixsum[i]=max(prefixsum[i-1],nums[i]);
        }

        for(int i=n-1;i>=0;i--){
            suffixsum[i]=min(suffixsum[i+1],nums[i]);
        }

        for(int i=0;i<=n;i++){
            if(prefixsum[i]-suffixsum[i]<=k){
                return i;
            }
        }
        return -1;
    }
};