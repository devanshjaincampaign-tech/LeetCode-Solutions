class Solution {
private:
    int climbmemo(int n,vector<int>&memo){
        if(n==0)return 1;
        if(n==1)return 1;

        if(memo[n]!=-1){
            return memo[n];
        }
        memo[n]=climbmemo(n-1,memo)+climbmemo(n-2,memo);
        return memo[n];
    }
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        vector<int>memo(n+1,-1);
        return climbmemo(n,memo);
    }
};