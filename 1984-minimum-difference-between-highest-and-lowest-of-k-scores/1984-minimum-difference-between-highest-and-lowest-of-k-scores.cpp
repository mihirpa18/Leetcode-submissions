class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int i=0,j=k-1;
        int maxi=nums[j];
        int mini=nums[i];
        int res=maxi-mini;
        while(i<n && j<n){
            maxi=nums[j];
            mini=nums[i];
            i++;
            j++;

            res=min(res,maxi-mini);
        }

        return res;
    }
};