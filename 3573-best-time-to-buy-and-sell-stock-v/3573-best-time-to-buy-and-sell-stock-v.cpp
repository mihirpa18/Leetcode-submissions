class Solution {
    long long profit(int i,int state,vector<int>&prices,int k,vector<vector<vector<long long>>>&dp){
        if(i>=prices.size()){
            if(state==2) return INT_MIN;
            return 0;
        };
        if(k==0) return 0;
        if(dp[i][state][k]!=-1) return dp[i][state][k];

        long long prof=0;

        //normal buy or short sell
        if(state==0){
           long long skip=profit(i+1,0,prices,k,dp);
           long long purch=-prices[i]+profit(i+1,1,prices,k,dp);
           long long shortSell=prices[i]+profit(i+1,2,prices,k,dp);

           prof=max(skip,max(purch,shortSell));
        }
        else if (state==1){
            long long skip=profit(i+1,1,prices,k,dp);
            long long sell=prices[i]+profit(i+1,0,prices,k-1,dp);

            prof=max(skip,sell);
        }
        else{
            long long skip=profit(i+1,2,prices,k,dp);
            long long buyBack=-prices[i]+profit(i+1,0,prices,k-1,dp);

            prof=max(skip,buyBack);
        }

        return dp[i][state][k]=prof;
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(3,vector<long long>(k+1,-1)));

        return profit(0,0,prices,k,dp);
    }
};