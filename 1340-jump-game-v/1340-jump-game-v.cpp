class Solution {
    int n;
    int solve(int i, vector<int>& nums, int d,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];

        int j = i+1;
        int k = d;
        int front = 0, back = 0;
        while(j<n && k--){
            if(nums[j] >= nums[i]) break;
            front = max(front,1 + solve(j, nums, d, dp));
            j++;
        }
        j = i-1;
        k = d;
        while(j>=0 && k--){
            if(nums[j] >= nums[i]) break;
            back = max(back, 1 + solve(j, nums, d, dp));
            j--;
        }

        return dp[i] = max(front,back);
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        int res = 0;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            res = max(res, solve(i, arr, d, dp));
        }

        return res+1;
    }
};