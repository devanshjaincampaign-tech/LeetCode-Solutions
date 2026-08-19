class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF=1e9;
        vector<vector<pair<int,int>>>graph(n+1);
        for(const auto& p:times){
            int u=p[0];
            int v=p[1];
            int w=p[2];

            graph[u].push_back({v,w});
        }

        vector<int>dist(n+1,INF);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0, k});

        while(!pq.empty()){
            auto[d,u]=pq.top();pq.pop();
            if(d>dist[u])continue;
            for(auto& edge:graph[u]){
                int target=edge.first;
                int weight=edge.second;

                if(dist[target]>dist[u]+weight){
                    dist[target]=dist[u]+weight;
                    pq.push({dist[target],target});
                }
            }
        }
        
        int max_time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) {
                return -1; 
            }
            max_time = max(max_time, dist[i]);
        }
        return max_time;
    }
};