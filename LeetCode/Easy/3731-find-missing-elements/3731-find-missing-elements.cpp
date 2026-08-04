class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int  min=INT_MAX;
        int max=INT_MIN;
        unordered_set<int>st;
        vector<int>finalans;
        for(int i:nums){
            if(i<min){
                min=i;
            }
            if(i>max){
                max=i;
            }

            st.insert(i);
        }

        for(int i=min;i<=max;i++){
            if(st.find(i)==st.end()){
                finalans.push_back(i);
            }
        }
        return finalans;
    }
};