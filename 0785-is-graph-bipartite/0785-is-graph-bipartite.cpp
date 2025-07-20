class Solution {
    bool dfs(int i,int c,vector<vector<int>>&adj,vector<int>&col){
        col[i]=c;
        for(auto it:adj[i]){
            if(col[it]==-1){
                if(!dfs(it,!c,adj,col)) return false;
            }
            else if(col[it]==c){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!dfs(i,0,adj,col)) return false;
            }
        }

        return true;
    }
};