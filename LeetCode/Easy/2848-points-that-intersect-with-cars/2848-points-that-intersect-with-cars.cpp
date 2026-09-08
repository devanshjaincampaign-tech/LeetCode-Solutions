class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>size(102,0);
        for(int i=0;i<nums.size();i++){
            int start=nums[i][0];
            int end=nums[i][1];

            for(int j=start;j<=end;j++){
                size[j]=1;
            }
        }
        int count=0;
        for(int i:size){
            if(i==1){
                count++;
            }
        }
        return count;
    }
};