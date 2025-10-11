class Solution {
    typedef long long ll;
    unordered_map<ll,ll>mp;
    ll maxDamage(int i,vector<ll>&vec,vector<int>&dp){
        if(i>=vec.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        ll notTake=maxDamage(i+1,vec,dp);
        auto j=lower_bound(vec.begin()+i+1,vec.end(),vec[i]+3)-vec.begin();
        ll take=vec[i]*mp[vec[i]]+maxDamage(j,vec,dp);

        return dp[i]=max(take,notTake);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        
        for(auto it:power) mp[it]++;
        int n=mp.size();
        vector<ll>vec;
        for(auto it:mp) vec.push_back(it.first);
        sort(vec.begin(),vec.end());
        vector<int>dp(n,-1);
        return maxDamage(0,vec,dp);

    }
};