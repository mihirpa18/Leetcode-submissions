class Solution {
    int solve(int i, int buy, vector<int>&prices, int fee,vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit;
        if(buy){
            profit = max(-prices[i]+solve(i+1,0,prices,fee,dp),solve(i+1,1,prices,fee,dp));
        }
        else profit = max((prices[i]-fee)+solve(i+1,1,prices,fee,dp),solve(i+1,0,prices,fee,dp));

        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return solve(0,1,prices,fee,dp);
    }
};