class Solution {
    // int paths(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&dp){
    //     if(r==0 && c==0){
    //         return 1;
    //     }
    //     if(r<0 || c<0 || grid[r][c]==1) return 0;
    //     if(dp[r][c]!=-1) return dp[r][c];

    //     int l=paths(r,c-1,grid,dp);
    //     int u=paths(r-1,c,grid,dp);

    //     return dp[r][c]=l+u;
    // }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));

        if(obstacleGrid[0][0]==1) return 0;
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){              
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else{
                    if(i>0) dp[i][j]+=dp[i-1][j];
                    if(j>0) dp[i][j]+=dp[i][j-1];
                }

            }
        }
        return dp[m-1][n-1];
    }
};