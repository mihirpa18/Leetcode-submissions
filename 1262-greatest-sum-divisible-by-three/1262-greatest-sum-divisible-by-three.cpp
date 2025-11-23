class Solution {
    int res=0;
    int maxSum(int i,int temp,vector<int>&nums,vector<vector<int>>&dp){
        cout<<temp<<" ";
        if(i>=nums.size()){
            return (temp==0)?0:INT_MIN;
        } 
        if(dp[i][temp]!=-1) return dp[i][temp];

        int pick=maxSum(i+1,(temp+nums[i])%3,nums,dp);
        if(pick!=INT_MIN) pick+=nums[i];

        int notPick=maxSum(i+1,temp,nums,dp);

        return dp[i][temp]=max(pick,notPick);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<vector<int>>dp(n,vector<int>(3,-1));

        return maxSum(0,0,nums,dp);
    }
};