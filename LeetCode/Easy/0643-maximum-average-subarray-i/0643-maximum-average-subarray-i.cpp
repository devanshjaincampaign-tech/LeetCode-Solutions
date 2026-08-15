class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curr_sum=0;
        for(int i=0;i<k;i++){
            curr_sum+=nums[i];
        }

        int max_sum=curr_sum;

        for(int i=k;i<nums.size();i++){
            curr_sum+=nums[i];
            curr_sum-=nums[i-k];
            max_sum=max(curr_sum,max_sum);
        }

        return (double)max_sum/k;
    }
};