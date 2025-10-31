class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        vector<int>mp(n,0);
        for(auto &it:nums){
            if(mp[it]>0) res.push_back(it);
            mp[it]++;
        }

        return res;
    }
};