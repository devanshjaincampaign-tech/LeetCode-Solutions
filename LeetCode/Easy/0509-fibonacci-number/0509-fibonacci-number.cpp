class Solution {
private:
    int fibmemo(vector<int>& memo, int n){
        if(n<=1)return n;

        if(memo[n]!=-1)return memo[n];

        memo[n]=fibmemo(memo,n-1)+fibmemo(memo,n-2);
        return memo[n];
    }
public:
    int fib(int n) {
        vector<int>memo(n+1,-1);
        int finalans=fibmemo(memo,n);
        return finalans;
    }
};