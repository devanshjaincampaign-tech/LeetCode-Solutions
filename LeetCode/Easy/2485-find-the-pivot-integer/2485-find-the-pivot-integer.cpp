class Solution {
public:
    int pivotInteger(int n) {
        for(int i=1;i<=n;i++){
            int suml=0;
            for(int j=1;j<=i;j++){
                suml=suml+j;
            }
            int sumr=0;
            for(int k=i;k<=n;k++){
                sumr=sumr+k;
            }
            if(sumr==suml){
                return i;
            }
        }
        return -1;
    }
};