class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int totalsum=0;
        for(int i: arr){
            totalsum+=i;
        }

        if(arr.size()<3){
            return totalsum;
        }

        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if((j-i+1)%2!=0){
                    for(int k=i;k<=j;k++){
                        totalsum+=arr[k];
                    }
                }
            }
        }

        return totalsum;
    }
};