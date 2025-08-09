class Solution {
    int solve(int i,int sum,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(i>=coins.size() || sum>amount){
            return 0;
        }
        if(sum==amount){
            return 1;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];

        int take=solve(i,sum+coins[i],amount,coins,dp);
        int notTake=solve(i+1,sum,amount,coins,dp);

        return dp[i][sum]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(0,0,amount,coins,dp);
    }
};