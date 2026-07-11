class Solution {
    int n;
    int m;
    int solve(int i,int j,string &s, string &t,vector<vector<int>>&dp){
        if(j == m) return 1;
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            int take = solve(i+1,j+1,s,t,dp);
            int notTake = solve(i+1,j,s,t,dp);

            return dp[i][j] = take+notTake;
        }
        else{
            return dp[i][j] = solve(i+1,j,s,t,dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(0,0,s,t,dp);
    }
};