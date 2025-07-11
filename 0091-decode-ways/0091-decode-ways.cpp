class Solution {
    int decode(int ind,string &s,vector<int>&dp,int &n){
        if(ind>=n){
            return 1;
        }
        if(s[ind]=='0') return 0;

        if(dp[ind]!=-1) return dp[ind];

        int res1=decode(ind+1,s,dp,n);
        int res2=0;
        if(ind+1<n){
            if(s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6')){
                res2=decode(ind+2,s,dp,n);
            }
        }
        return dp[ind]=res1+res2;
    }
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);

        return decode(0,s,dp,n);
    }
};