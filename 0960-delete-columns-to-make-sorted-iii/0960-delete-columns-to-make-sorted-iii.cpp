class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        int n=str.size();
        int m=str[0].size();
        vector<int>dp(m,1);
        int maxi=1;
        
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                bool flag=true;
                for(int k=0;k<n;k++){
                    if(str[k][j]>str[k][i]){
                        flag=false;
                        break;
                    }
                }

                if(flag) dp[i]=max(dp[i],dp[j]+1);
            }
            maxi=max(maxi,dp[i]);
        }
        cout<<maxi<<" ";
        return m-maxi;
    }
};