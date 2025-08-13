class Solution {
    int solve(int i,int j,vector<vector<int>>&tri,vector<vector<int>>&dp){
        if(i>=tri.size() || j>=tri.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int f=tri[i][j]+solve(i+1,j,tri,dp);
        int s=tri[i][j]+solve(i+1,j+1,tri,dp);

        return dp[i][j]=min(f,s);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp=triangle;

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=triangle[i].size()-1;j++){
                dp[i][j]=dp[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};