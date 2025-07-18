class Solution {
    int subseq(int i,int l,vector<int>&nums,int &n,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][l+1]!=-1) return dp[i][l+1];

        dp[i][l+1]=subseq(i+1,l,nums,n,dp);
        if(l==-1 || nums[i]>nums[l]){
            dp[i][l+1]=max(dp[i][l+1],1+subseq(i+1,i,nums,n,dp));
        }
        
        return dp[i][l+1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int maxi=subseq(0,-1,nums,n,dp); 
        return maxi;
    }
};