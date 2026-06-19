class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        for(int i:nums){
            for(int j:nums){
                if(abs(i-j)==k){
                    count++;
                }
            }
        }
        return count/2;
    }
};