class disjoint{
    public:
        vector<int>parent,size;

        disjoint(int n){
            parent.resize(n+1);
            size.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }

        int findParent(int u){
            if(parent[u]==u) return u;
            return parent[u]=findParent(parent[u]);
        }

        void ubs(int u,int v){
            int upu=findParent(u);
            int upv=findParent(v);
            if(upu==upv) return;

            if(size[upu]<size[upv]){
                parent[upu]=upv;
                size[upv]+=size[upu];
            }
            else{
                parent[upv]=upu;
                size[upu]+=size[upv];
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>map;
        disjoint ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(map.find(accounts[i][j])==map.end()){
                    map[accounts[i][j]]=i;

                }
                else{
                    ds.ubs(i,map[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>>res(n);
        for(auto it:map){
            int ind=ds.findParent(it.second);
            string temp=it.first;
            res[ind].push_back(temp);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(res[i].size()==0) continue;
            sort(res[i].begin(),res[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:res[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};