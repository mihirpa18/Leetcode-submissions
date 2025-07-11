class Solution {
    void dfs(int r,int c,vector<vector<int>>& heights,vector<vector<bool>>& vis,int &n,int &m){
        vis[r][c]=true;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(nr,nc,heights,vis,n,m);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>atl(n,vector<bool>(m,false));

        for(int i=0;i<m;i++){
            dfs(0,i,heights,pac,n,m);
            dfs(n-1,i,heights,atl,n,m);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,heights,pac,n,m);
            dfs(i,m-1,heights,atl,n,m);
        }

        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};