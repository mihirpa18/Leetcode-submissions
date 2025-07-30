class Solution {
    // int profit(int i,int buy,vector<int>&prices,vector<vector<int>>&dp){
    //     if(i==prices.size()) return 0;
    //     if(dp[i][buy]!=-1) return dp[i][buy];

    //     int prof=0;
    //     if(buy){
    //         prof=max(-prices[i]+profit(i+1,0,prices,dp),profit(i+1,1,prices,dp));
    //     }
    //     else{
    //         prof=max(prices[i]+profit(i+1,1,prices,dp),profit(i+1,0,prices,dp));
    //     }

    //     return dp[i][buy]=prof;
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>next(2,0),curr(2,0);
        next[0]=0;
        next[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int prof=0;
                if(j){
                    prof=max(-prices[i]+next[0],next[1]);
                }
                else{
                    prof=max(prices[i]+next[1],next[0]);
                }
                curr[j]=prof;
            }
            next=curr;
        }
        return next[1];
    }
};