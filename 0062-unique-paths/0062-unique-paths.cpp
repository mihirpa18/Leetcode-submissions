class Solution {
    // int paths(int r,int c,vector<vector<int>>&dp){
    //     if(r==0 && c==0) return 1;
    //     if(r<0 || c<0){
    //         return 0;
    //     }
    //     if(dp[r][c]!=-1) return dp[r][c];

    //     int l=paths(r-1,c,dp);
    //     int u=paths(r,c-1,dp);

    //     return dp[r][c]=l+u;
    // }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    if(i>0) dp[i][j]+=dp[i-1][j];
                    if(j>0) dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};