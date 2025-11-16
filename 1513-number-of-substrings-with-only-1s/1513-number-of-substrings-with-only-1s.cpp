class Solution {
public:
    int numSub(string s) {
        int i=0,j=0;
        int n=s.size();
        long long res=0;
        int mod=1e9+7;
        while(i<n && j<n){
            if(s[j]=='0'){
                j++;
                i=j;
            }
            else{
                while(s[j]=='1'){
                    j++;
                }
            }
            long long num=(j-i)%mod;
            res=(res+(num*(num+1)%mod)/2%mod);
            i=j;
        }

        return res;
    }
};