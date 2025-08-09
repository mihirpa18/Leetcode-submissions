class Solution {
    int solve(int i,int m,int n,vector<string>&s,vector<vector<vector<int>>>&dp){
        int nz=0,no=0;
        if(i>=s.size()) return 0;
        if(m<0 || n<0) return 0;
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]=='1') no++;
            else if(s[i][j]=='0') nz++;
        }       
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int take=INT_MIN,notTake;
        if(nz>m || no>n){
            notTake=solve(i+1,m,n,s,dp);
        }
        else{
            take=1+solve(i+1,m-nz,n-no,s,dp);
            notTake=solve(i+1,m,n,s,dp);
        }
        
        return dp[i][m][n]=max(take,notTake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int x=strs.size();
        vector<vector<vector<int>>>dp(x,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,strs,dp);
    }
};