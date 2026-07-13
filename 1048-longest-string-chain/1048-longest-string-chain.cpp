class Solution {
    bool isChain(string &a,string &b){
        if(b.size() != a.size()+1) return false;
        int i = 0, j = 0;

        while(i<b.size()){
            if(j<a.size() && a[j] == b[i]){
                i++,j++;
            }
            else{
                i++;
            }
        } 

        if(i == b.size() && j == a.size()) return true;

        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        int n=words.size();
        int res=1;
        
        vector<int>dp(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isChain(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j]+1);

                    res = max(res,dp[i]);
                }
            }
        }

        return res;

    }
};