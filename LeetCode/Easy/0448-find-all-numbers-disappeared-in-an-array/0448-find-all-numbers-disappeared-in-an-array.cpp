class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>finalans;
        int n=nums.size();
        vector<int>count(n+1,0);
        count[0]=1;
        for(int i:nums){
            count[i]++;
        }
        for(int i=1;i<count.size();i++){
            if(count[i]==0){
                finalans.push_back(i);
            }
        }
        return finalans;
    }
};