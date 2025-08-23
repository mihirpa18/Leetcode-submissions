class Solution {
    int find(int i,int sum,vector<int>&res,vector<vector<int>>&dp){
        if(i>=res.size() || sum<0) return 0;

        if(sum==0) return 1;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take=find(i,sum-res[i],res,dp);
        int notTake=find(i+1,sum,res,dp);

        return dp[i][sum]=take+notTake;
    }
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int>res;
        int n=numWays.size();
        
        for(int i=1;i<=n;i++){
            
            if(res.size()==0) res.push_back(i);
            vector<vector<int>>dp(res.size(),vector<int>(i+1,-1));

            int c=find(0,i,res,dp);
            // cout<<numWays[i-1]<<" "<<c<<"-";
            // if(c>numWays[i-1]){
            //         res.clear();
            //         break;
            // }
          
            if(c<numWays[i-1]){
                res.push_back(i);
                vector<vector<int>>dp2(res.size(),vector<int>(i+1,-1));
                c=find(0,i,res,dp2);   
            }
            if(c!=numWays[i-1]){
                    res.clear();
                    break;
            }
            // cout<<c<<" ";
        }

        return res;
    }
};