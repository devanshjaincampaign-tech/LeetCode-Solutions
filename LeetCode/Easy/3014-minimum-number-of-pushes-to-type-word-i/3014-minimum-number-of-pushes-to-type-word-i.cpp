class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int sum=0;
        if(n<=8)return n;
        if(n>8 && n<=16){
            sum=8+(n-8)*2;
        }
        else if(n>16 && n<=24){
            sum=24+(n-16)*3;
        }
        else{
            sum=48+(n-24)*4;
        }
        return sum;
    }
};