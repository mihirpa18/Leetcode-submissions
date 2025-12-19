class Solution {
    void dfs(int i,vector<vector<int>>&adj,int time,vector<int>&res){
        res.push_back(i);
        for(auto &it:adj[i]){
            cout<<it[0];
            if(it[1]<time) continue;
            else{
                dfs(it[0],adj,it[1],res);
            }
        }
    }

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int>res;
        vector<vector<int>>adj(n,vector<int>(2,0));

        for(auto &it:meetings){
            adj[it[0]].push_back({it[1],it[2]});
        }

        res.push_back(0);
        
        dfs(firstPerson,adj,0,res);

        return res;
    }
};