class Solution {
private:
    void dfs(int ind,vector<vector<int>>&adj,vector<int>&vis,set<int>&st){
        vis[ind]=1;
        st.insert(ind);
        for(auto &it:adj[ind]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        map<int,set<int>>mp;
        vector<vector<int>>adj(c+1);
        for(auto &it:connections){  
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(c+1,0);
        int count=0;
        vector<int>comp(c+1);
        int id=1;
        for(int i=1;i<=c;i++){
            if(vis[i]){
                continue;
            }
            id=i;
            set<int>st;
            dfs(i,adj,vis,st);
            mp[id]=st;

            for(auto &it:st){
                comp[it]=i;
            }
        }
        vector<int>res;
        for(auto &it:queries){
            int which_comp=comp[it[1]];
            if(it[0]==1){
                if(mp[which_comp].count(it[1])!=0){
                    res.push_back(it[1]);
                }
                else if(!mp[which_comp].empty()){
                    res.push_back(*mp[which_comp].begin());
                }
                else{
                    res.push_back(-1);
                }
            }
            else{
                mp[which_comp].erase(it[1]);
            }
        }

        return res;


    }
};