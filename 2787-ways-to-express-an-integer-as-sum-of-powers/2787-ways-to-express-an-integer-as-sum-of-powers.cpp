class Solution {
    int mod=1e9+7;
    int ways(int i,int target,vector<long>&ans,vector<vector<long>>&dp){
        if(target==0) return 1;
        if(i>=ans.size() || target<0){
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int take=ways(i+1,target-ans[i],ans,dp);
        int notTake=ways(i+1,target,ans,dp);

        return dp[i][target]=(take+notTake)%mod;
    }
public:
    int numberOfWays(int n, int x) {
        vector<long>ans;
        for(int i=1;i<=n;i++){
            if(pow(i,x)<=n){
                ans.push_back(pow(i,x));
            }
        }
        int len=ans.size();
        vector<vector<long>>dp(len+1,vector<long>(n+1,-1));

        return ways(0,n,ans,dp);
    }
};