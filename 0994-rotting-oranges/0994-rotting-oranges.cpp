class Solution {
     void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<long>>& vis,int &n,int &m,int val){
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m  && grid[nr][nc]==1 && val<vis[nr][nc]){
                vis[nr][nc]=val;
                dfs(nr,nc,grid,vis,n,m,val+1);
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long>>vis(n,vector<long>(m,INT_MAX));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=0;
                    dfs(i,j,grid,vis,n,m,1);
                }
            }
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(vis[i][j]==INT_MAX) return -1;
                    maxi=max(maxi,(int)vis[i][j]);
                }
                
                
            }
        }
        return maxi;
    }
};