class Solution {
    // int count = 0;
    // int n;
    // int solve(int i,vector<int>&nums, int target, vector<int>&dp){
    //     if(i == n-1){
    //         return 0;
    //     }

    //     if(dp[i] != -1) return dp[i];

    //     int ans = INT_MIN;
    //     for(int j = i+1; j<n; j++){
    //         if(abs(nums[j]-nums[i]) <= target){
    //             ans = max(ans,1 + solve(j, nums, target, dp));
    //         }
    //     }

    //     return dp[i] = ans;
    // }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n,INT_MIN);
        dp[0] = 0;
        // int res = solve(0, nums, target,dp);
        for(int i = 1; i<n; i++){
            for(int j=0; j<i; j++){
                if(abs(nums[j]-nums[i]) <= target){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
        }

        return (dp[n-1]<0)?-1:dp[n-1];
    }
};