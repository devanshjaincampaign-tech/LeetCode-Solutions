class Solution {
private:
    int fibmemo(int n,vector<int>&memo){
        if(n<=1){
            return n;
        }
        if(memo[n]!=-1){
            return memo[n];
        }
        memo[n]=fibmemo(n-1,memo)+fibmemo(n-2,memo);
        return memo[n];
    }
public:
    int fib(int n) {
        if(n<=1)return n;
        vector<int>memo(n+1,-1);
        return fibmemo(n,memo);
    }
};