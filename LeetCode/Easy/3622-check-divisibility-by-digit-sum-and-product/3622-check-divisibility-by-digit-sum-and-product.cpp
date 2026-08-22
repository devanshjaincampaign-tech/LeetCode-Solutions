class Solution {
public:
    bool checkDivisibility(int n) {
        long long x=n;
        long long sum=0;
        long long product=1;

        while(x!=0){
            sum+=x%10;
            product*=x%10;
            x/=10;
        }

        return (n%(sum+product)==0);
    }
};