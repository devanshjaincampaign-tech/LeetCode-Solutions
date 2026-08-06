class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>vec(n+22,0);
        for(const auto& pair:edges){
            int u=pair[0];
            int v=pair[1];

            vec[u]++;vec[v]++;
        }

        for(int i=1;i<=n+1;i++){
            if(vec[i]==n){
                return i;
            }
        }

        return -1;
    }
};