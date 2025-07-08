class Solution {
public:
    // int robHelp(int ind,vector<int>&nums,vector<int>&dp){
    //     if(ind==0) return nums[0];
    //     if(ind<0) return 0;

    //     if(dp[ind]!=-1) return dp[ind];
    //     int pick=nums[ind]+robHelp(ind-2,nums,dp);
    //     int notPick=0+robHelp(ind-1,nums,dp);

    //     return dp[ind]=max(pick,notPick);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        if(n==1) return nums[0];
        dp[0]= nums[0];
        dp[1]= max(nums[0],nums[1]);
        for(int ind=2;ind<n;ind++){
            int pick=nums[ind]+dp[ind-2];
            int notPick=0+dp[ind-1];
            dp[ind]=max(pick,notPick);
        }
        

        return dp[n-1];
    }
};