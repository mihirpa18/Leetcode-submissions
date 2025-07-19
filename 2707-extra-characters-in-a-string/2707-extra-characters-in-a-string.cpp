class Solution {
    int extra(int i,string &s,unordered_set<string>&set,int &n,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        dp[i]=extra(i+1,s,set,n,dp)+1;
        for(int j=i;j<n;j++){
            string temp=s.substr(i,j-i+1);
            if(set.find(temp)!=set.end()){
                dp[i]=min(dp[i],extra(j+1,s,set,n,dp));
            }
        }

        return dp[i];
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
        unordered_set<string>set(dictionary.begin(),dictionary.end());
        vector<int>dp(n,-1);
        int res=extra(0,s,set,n,dp);
        return res;
    }
};