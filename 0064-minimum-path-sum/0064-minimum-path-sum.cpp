class Solution {
    long path(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(r==0 && c==0) return grid[0][0];
        if(r<0 || c<0) return INT_MAX;
        if(dp[r][c]!=-1) return dp[r][c];
        long ls=grid[r][c]+path(r,c-1,grid,dp);
        long us=grid[r][c]+path(r-1,c,grid,dp);

        return dp[r][c]=min(ls,us);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return path(n-1,m-1,grid,dp);
    }
};