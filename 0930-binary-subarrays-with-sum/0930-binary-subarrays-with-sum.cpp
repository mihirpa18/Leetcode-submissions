class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = 1;
        int sum = 0;
        int res=0;

        for(int j=0; j<n;j++){
            sum += nums[j];
            if(mp.find(sum-goal) != mp.end()){
                res+=mp[sum-goal];
            }

            mp[sum]++;
        }

        return res;
    }
};