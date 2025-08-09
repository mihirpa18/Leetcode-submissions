class Solution {
    int dist(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0 && j<0) return 0;
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        int match=INT_MAX;
        if(s[i]==t[j]){
            match=dist(i-1,j-1,s,t,dp);
        }
        int rep=1+dist(i-1,j-1,s,t,dp);
        int add=1+dist(i,j-1,s,t,dp);
        int del=1+dist(i-1,j,s,t,dp);

        return dp[i][j]=min(min(add,match),min(rep,del));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return dist(n-1,m-1,word1,word2,dp);
    }
};