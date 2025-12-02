class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        long long mod=1e9+7;
        long long res=0,sum=0;
        for(auto &it:points){
            mp[it[1]]++;
        }

        for(auto &it:mp){
            long long temp=(long long)it.second*(it.second-1)/2;
            res+=temp*sum;
            sum+=temp;
        }

        return res%mod;
    }
};