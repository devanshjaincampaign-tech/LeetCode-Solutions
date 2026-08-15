class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int total=threshold*k;
        int count=0;

        int curr_sum=0;
        for(int i=0;i<k;i++){
            curr_sum+=arr[i];
        }

        if(curr_sum>=total){
            count++;
        }

        int max_sum=curr_sum;

        for(int i=k;i<arr.size();i++){
            curr_sum=curr_sum+arr[i]-arr[i-k];
            if(curr_sum>=total){
                count++;
            }
        }
        return count;
    }
};