class Solution {
    // int profit(int i,int buy,vector<int>&prices,vector<vector<int>>&dp){
    //     if(i>=prices.size()){
    //         return 0;
    //     }
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     int prof;
    //     if(buy){
    //         prof=max(-prices[i]+profit(i+1,0,prices,dp),profit(i+1,1,prices,dp));
    //     }
    //     else{
    //         prof=max(prices[i]+profit(i+2,1,prices,dp),profit(i+1,0,prices,dp));
    //     }

    //     return dp[i][buy]=prof;
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1){
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][0];
    }
};