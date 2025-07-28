class Solution {
    // int longest(int i,int j,string &text1,string &text2,vector<vector<int>>&dp){
    //     if(i>=text1.size() || j>= text2.size()){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int match=0;
    //     int notMatch=0;
    //     if(text1[i]==text2[j]){
    //         match= 1+longest(i+1,j+1,text1,text2,dp);
    //     }  
    //     else{
    //         notMatch=max(longest(i+1,j,text1,text2,dp),longest(i,j+1,text1,text2,dp));
    //     }

    //     return dp[i][j]=max(match,notMatch);
    // }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int j=0;j<=n;j++){
            dp[j][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }

                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};