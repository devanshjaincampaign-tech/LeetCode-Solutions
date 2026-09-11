class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool>range(right+1,false);
        for(int i=0;i<ranges.size();i++){
            for(int j=ranges[i][0];j<=ranges[i][1];j++){
                if(j>=left && j<=right && range[j]==false){
                    range[j]=true;
                }
            }
        }

        for(int i=left;i<=right;i++){
            if(range[i]==false){
                return false;
            }
        }
        return true;
    }
};