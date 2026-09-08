class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int boundary =0;
        int count=0;
        for(int i:nums){
            boundary+=i;
            if(boundary==0){
                count++;
            }
        }

        return count;
    }
};