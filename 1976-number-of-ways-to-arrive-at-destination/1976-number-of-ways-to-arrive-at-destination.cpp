class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<vector<pair<long,long>>>adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<pair<long,int>>> q;

        vector<long>dist(n,LLONG_MAX);
        vector<long>way(n,0);
        q.push({0,0});
        dist[0]=0;
        way[0]=1;
        while(!q.empty()){
            auto [d,node]=q.top();
            q.pop();
            if(d>dist[node]) continue;
            for(auto it:adj[node]){
                int nw=it.second;
                int nn=it.first;
                if(nw+dist[node]<dist[nn]){
                    dist[nn]=nw+dist[node];
                    way[nn]=way[node];
                    q.push({dist[nn],nn});
                }
                else if(nw+dist[node]==dist[nn]){
                    way[nn]=(way[node]+way[nn])%mod;
                }
            }
        }

        return way[n-1]%mod;
    }
};