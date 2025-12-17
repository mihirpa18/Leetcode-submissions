class Solution {
    int maxProfit(int i,int k,int buy,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(k==0) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        int profit;
        if(buy){
            profit=max(-prices[i]+maxProfit(i+1,k,0,prices,dp),maxProfit(i+1,k,1,prices,dp));
        }
        else{
            profit=max(prices[i]+maxProfit(i+1,k-1,1,prices,dp),maxProfit(i+1,k,0,prices,dp));
        }

        return dp[i][buy][k]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return maxProfit(0,k,1,prices,dp);
    }
};