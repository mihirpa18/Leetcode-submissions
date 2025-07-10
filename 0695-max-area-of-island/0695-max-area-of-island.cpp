class Solution {
    void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis,int &area,int &n,int &m){
        
        vis[r][c]=1;
        area+=1;

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                dfs(nr,nc,grid,vis,area,n,m);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int area=0;
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,grid,vis,area,n,m);
                }
                maxArea=max(area,maxArea);
            }
        }

        return maxArea;
    }
};