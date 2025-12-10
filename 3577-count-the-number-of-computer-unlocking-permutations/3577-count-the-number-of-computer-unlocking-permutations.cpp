class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        if(*min_element(complexity.begin()+1,complexity.end())<=complexity[0]) return 0;
        int res=1;
        int mod=1e9+7;
        for(int i=n-1;i>0;i--){
            res=(1ll*res*i)%mod;
        }
        return res;
    }
};