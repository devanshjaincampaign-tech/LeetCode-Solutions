class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int  min=INT_MAX;
        int max=INT_MIN;
        
        vector<int>finalans;
        for(int i:nums){
            if(i<min){
                min=i;
            }
            if(i>max){
                max=i;
            }
        }
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=min;i<=max;i++){
            if(st.find(i)==st.end()){
                finalans.push_back(i);
            }
        }
        return finalans;
    }
};