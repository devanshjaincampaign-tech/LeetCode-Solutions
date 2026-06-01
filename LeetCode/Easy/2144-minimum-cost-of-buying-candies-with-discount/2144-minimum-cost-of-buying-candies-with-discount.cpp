class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int sum=0;
        if(n==0) return 0;
        sort(cost.begin(),cost.end(),greater<int>());
        for(int i=0;i<n;i++){
            if((i+1)%3==0){
                continue;
            }
            else{
                sum=sum+cost[i];
            }
        }
        return sum;
    }
};