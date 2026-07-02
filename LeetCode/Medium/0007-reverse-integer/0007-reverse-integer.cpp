class Solution {
public:
    int reverse(int x) {
        long long s=x;
        if(s<0){
            s=-s;
        }
        long long rev=0;
        while(s!=0){
            rev=rev*10+(s%10);
            s=s/10;
            
        }

        if(abs(rev)>INT_MAX)return 0;
        if(x<0){
            return -rev;
        }
        return rev;
    }
};