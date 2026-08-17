class Solution {
private:
    bool dfs(int i,vector<vector<int>>&adj,vector<int>&state,vector<int>&order){
        state[i]=1;

        for(int nbr: adj[i]){
            if(state[nbr]==1){
                return false;
            }

            if(state[nbr]==0){
                if(!dfs(nbr,adj,state,order))return false;
            }
    
        }

        state[i]=2;
        order.push_back(i);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*vector<vector<int>>adj(numCourses);
        vector<int>inorder(numCourses+1,0);

        for(const auto& p: prerequisites){
            int u=p[1];
            int v=p[0];

            adj[u].push_back(v);
            inorder[v]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        int count=0;
        vector<int>topOrder;
        while(!q.empty()){
            int node=q.front();q.pop();
            count++;
            topOrder.push_back(node);

            for(int neighbour: adj[node]){
                inorder[neighbour]--;

                if(inorder[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

        if(count!=numCourses)return {};
        return topOrder;*/

        vector<vector<int>>adj(numCourses);
        vector<int>state(numCourses,0);
        vector<int>order;

        for(const auto& p: prerequisites){
            int u=p[1];
            int v=p[0];

            adj[u].push_back(v);
        }

        for(int i=0;i<numCourses;i++){
            if(state[i]==0){
                if(!dfs(i,adj,state,order)){
                    return {};
                }
            }
        }

        reverse(order.begin(),order.end());
        return order;
    }
};