class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum=0;
        for(int i: nums){
            totalsum+=i;
        }

        int target=totalsum-x;

        if(target==0)return nums.size();
        if(target<0)return -1;

        int maxlen=-1;
        int left=0;
        int currsum=0;
        
        for(int right=0;right<nums.size();right++){
            currsum+=nums[right];
            
            while(currsum>target && left<=right){
                currsum-=nums[left];
                left++;
            }

            if(currsum==target){
                maxlen=max(maxlen,right-left+1);
            }


        }
        return maxlen == -1 ? -1 : nums.size() - maxlen;
    }
};