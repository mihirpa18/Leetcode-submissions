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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        int mst=0;
        if(m<n-1) return -1;
        
        disjoint ds(n);
        for(auto it:connections){
            if(ds.findParent(it[0])!=ds.findParent(it[1])){
                ds.ubs(it[0],it[1]);
                mst++;
            }
        }

        int res=0,diff=m-mst;
        
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i) res++;
        }

        return res-1<=diff?res-1:-1;
    }
};