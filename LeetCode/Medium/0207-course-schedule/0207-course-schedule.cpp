class Solution {
private:
    bool dfs(int i,vector<vector<int>>&adj,vector<int>&state){
        state[i]=1;

        for(int nbr:adj[i]){
            if(state[nbr]==1){
                return false;
            }
            if(state[nbr]==0){
                if(!dfs(nbr,adj,state)){
                    return false;
                }
            }
        }
        state[i]=2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto& p : prerequisites) {
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbour : adj[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return count == numCourses;*/


        vector<vector<int>>adj(numCourses);
        vector<int>state(numCourses,0);

        for(const auto& p : prerequisites){
            int v=p[0];
            int u=p[1];

            adj[u].push_back(v);
        }

        for(int i=0;i<numCourses;i++){
            if(state[i]==0){
                if(!dfs(i,adj,state)){
                    return false;
                }
            }
        }
        return true;
    }
};