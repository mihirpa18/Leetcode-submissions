class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],2*it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>dist(n,1e9);
        dist[0]=0;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int wt=top.first;
            int node=top.second;
            if(wt>dist[node]) continue;
            for(auto it:adj[node]){
                int nw=it.second;
                int nn=it.first;
                if(dist[node]+nw<dist[nn]){
                    dist[nn]=dist[node]+nw;
                    pq.push({dist[nn],nn});
                }
            }
        }

        return dist[n-1]!=1e9?dist[n-1]:-1;
    }
};