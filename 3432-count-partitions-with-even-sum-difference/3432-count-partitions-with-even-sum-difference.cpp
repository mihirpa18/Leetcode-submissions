class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto &it:nums) sum+=it;
        int lsum=nums[0];
        int rsum=sum-lsum;
        int res=0;

        for(int i=1;i<n;i++){
            int diff=lsum-rsum;
            if(diff%2==0) res++;
            lsum+=nums[i];
            rsum-=nums[i];
        }

        return res;
    }
};