class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>dp(n+1,0);
        vector<long long>pref(n+1,0);
        dp[0]=1;
        pref[0]=1;
        deque<int>maxq,minq;
        int i=0;
        int mod=1e9+7;

        for(int j=0;j<n;j++){
            while(!maxq.empty() && nums[maxq.back()]<nums[j]) maxq.pop_back();
            maxq.push_back(j);
            while(!minq.empty() && nums[minq.back()]>nums[j]) minq.pop_back();
            minq.push_back(j);

            while(nums[maxq.front()]-nums[minq.front()]>k){
                if(i==maxq.front()) maxq.pop_front();
                if(i==minq.front()) minq.pop_front();

                i++;
            }

            long long ways=pref[j];
            if(i>0) ways=(ways-pref[i-1]+mod)%mod;
            dp[j+1]=ways;
            pref[j+1]=(pref[j]+dp[j+1])%mod;
        }
        return dp[n];
    }
};