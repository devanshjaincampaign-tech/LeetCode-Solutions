class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
        long sum=0;
        long x=0;
        while(n!=0){
            if(n%10!=0){
                x=x*10+(n%10);
                sum+=n%10;
            }
            n=n/10;
            
        }

        string s=to_string(x);
        reverse(s.begin(),s.end());

        long ans=0;
        for(char str:s){
            ans=ans*10+(str-'0');
        }
        return ans*sum;
    }
};