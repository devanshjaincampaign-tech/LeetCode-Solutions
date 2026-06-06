class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> smaller;
        for(int val: nums){
            int count=0;
            for(int val1: nums){
                if(val==val1){
                    continue;
                }
                else if(val1<val){
                    count++;
                }

            }
            smaller.push_back(count);
        }
        return smaller;
    }
};