class Solution {
    // int solve(int i,vector<int>&dp){
    //     if(i==0 || i==1) return 1;
    //     if(dp[i]!=-1) return dp[i];
    //     int res=0;
    //     for(int j=1;j<=i;j++){
    //         res+=solve(j-1,dp)*solve(i-j,dp);
    //     }
    //     return dp[i]=res;
    // }
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};