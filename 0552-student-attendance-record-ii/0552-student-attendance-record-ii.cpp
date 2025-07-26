class Solution {
    int m=1e9+7;
    int award(int i,int a,int l,vector<vector<vector<int>>>&dp){
        if(a>1 || l>2) return 0;
        if(i==0) return 1;
        if(dp[i][a][l]!=-1) return dp[i][a][l];

        int absent=award(i-1,a+1,0,dp);
        int late=award(i-1,a,l+1,dp);
        int present=award(i-1,a,0,dp);

        return dp[i][a][l]=((absent+late)%m+present)%m;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return award(n,0,0,dp);
    }
};