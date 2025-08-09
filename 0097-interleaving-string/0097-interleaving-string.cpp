class Solution {
    bool solve(int i,int j,string &s,string &t,string &r,vector<vector<int>>&dp){
        if(i==s.size() && j==t.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        int k=i+j;
        bool take=false,notTake=false;

        if(i<s.size() && s[i]==r[k]){
            take=solve(i+1,j,s,t,r,dp);
        }
        if(j<t.size() && t[j]==r[k]){
            notTake=solve(i,j+1,s,t,r,dp);
        }

        return dp[i][j]=take||notTake;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size();
        if(n+m!=s3.size()) return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};