class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        long long max_a=0;
        long long max_ab=0;

        for(int x:nums){
            ans=max(ans,max_ab*x);
            max_ab=max(max_ab,max_a-x);
            max_a=max(max_a,(long long)x);
        }
        return ans;
    }
};