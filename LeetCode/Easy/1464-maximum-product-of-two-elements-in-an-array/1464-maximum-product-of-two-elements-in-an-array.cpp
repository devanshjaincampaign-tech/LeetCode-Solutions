class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest=INT_MIN;
        int secondlargest=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=largest){
                secondlargest=largest;
                largest=nums[i];
                
            }
            else if(nums[i]>secondlargest){
                secondlargest=nums[i];
            }
        }

        return (largest-1)*(secondlargest-1);
    }
};