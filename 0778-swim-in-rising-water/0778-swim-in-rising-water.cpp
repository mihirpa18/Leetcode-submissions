class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int res=0;
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));

        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            res=max(res,top.first);
            cout<<res<<" ";
            int r=top.second.first;
            int c=top.second.second;
            if(r==n-1 && c==n-1) return res;
            int dr[4]={0,1,0,-1};
            int dc[4]={1,0,-1,0};
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<n && nr>=0 && nc<n && nc>=0 && !vis[nr][nc]){
                    pq.push({grid[nr][nc],{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }

        return res;
    }
};