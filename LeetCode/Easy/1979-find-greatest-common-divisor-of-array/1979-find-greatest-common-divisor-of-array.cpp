class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minelement=nums[0];
        int maxelement=nums[nums.size()-1];
        int GCD=0;
        for(int i=1;i<=minelement;i++){
            if(minelement%i==0 && maxelement%i==0){
                GCD=i;
            }
        }
        return GCD;
    }
};