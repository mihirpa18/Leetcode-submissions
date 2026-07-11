class Solution {
    int nodes;
    int degSum;
    void dfs(int i,vector<int>&vis,vector<vector<int>>&adj){
        nodes++;
        vis[i] = 1;
        degSum += adj[i].size();

        for(auto &e:adj[i]){
            if(!vis[e]) dfs(e,vis,adj);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int res = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                nodes = 0;
                degSum = 0;

                dfs(i,vis,adj);

                int numEdges = degSum/2;
                if(numEdges == nodes*(nodes-1)/2) res++;
            }
        }

        return res;
    }
};