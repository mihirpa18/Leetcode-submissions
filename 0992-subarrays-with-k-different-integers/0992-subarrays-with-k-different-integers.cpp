class Solution {
    int help(vector<int>&nums,int k){
        int res=0;
        int n=nums.size();
        int l=0,r=0;
        unordered_map<int,int>map;
        while(r<n){
            map[nums[r]]++;
            while(map.size()>k){
                map[nums[l]]--;
                if(map[nums[l]]==0) map.erase(nums[l]);
                l++;
            }
            res+=(r-l+1);
            r++;
        }

        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};