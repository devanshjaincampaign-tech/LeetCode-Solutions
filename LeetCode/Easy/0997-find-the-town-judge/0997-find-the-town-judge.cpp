class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trustscore(n+1,0);
        for(const auto& relations:trust){
            int u=relations[0];
            int v=relations[1];

            trustscore[u]--;
            trustscore[v]++;
        }

        for(int i=1;i<=n;i++){
            if(trustscore[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};