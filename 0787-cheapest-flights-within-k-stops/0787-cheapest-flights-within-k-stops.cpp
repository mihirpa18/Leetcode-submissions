class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;

        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int stop=top.first;
            int node=top.second.first;
            int cost=top.second.second;

            if(stop>k) continue;

            for(auto it:adj[node]){
                int near=it.first;
                int newCost=it.second;
                if(dist[near]>cost+newCost){
                    dist[near]=cost+newCost;
                    q.push({stop+1,{near,cost+newCost}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;

        return dist[dst];
    }
};