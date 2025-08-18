class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int z=0;
        int l=0,r=0;
        int res=0;
        while(l<n && r<n){
            if(nums[r]==1){
                res=max(res,r-l+1);
                r++;
            }
            else if(z<k && nums[r]==0){
                z++;
                res=max(res,r-l+1);
                r++;
            }
            else{
                while(z>=k){
                    if(nums[l]==0) z--;
                    l++;
                }
            }
        }

        return res;

    }
};