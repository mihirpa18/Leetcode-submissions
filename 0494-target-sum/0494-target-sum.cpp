class Solution {
    int find(int i,int sum,int target,vector<int>&nums,unordered_map<string,int>&dp){
        if(i<0 && sum==target){
            return 1;
        }
        if(i<0 && sum!=target) return 0;
        string s=to_string(i)+","+to_string(sum);
        if(dp.count(s)) return dp[s];
        int add=find(i-1,sum+nums[i],target,nums,dp);
        int sub=find(i-1,sum-nums[i],target,nums,dp);

        return dp[s]=add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(target,-1));
        unordered_map<string,int>dp;
        return find(n-1,0,target,nums,dp);
    }
};