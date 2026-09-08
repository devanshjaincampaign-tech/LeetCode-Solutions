class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixsum(n);
        vector<int>suffixsum(n);

        prefixsum[0]=0;
        suffixsum[n-1]=0;

        for(int i=1;i<nums.size();i++){
            prefixsum[i]=prefixsum[i-1]+nums[i-1];
        }

        for(int i=n-2;i>=0;i--){
            suffixsum[i]=suffixsum[i+1]+nums[i+1];
        }

        for(int i=0;i<n;i++){
            if(prefixsum[i]==suffixsum[i]){
                return i;
            }
        }
        return -1;
    }
};