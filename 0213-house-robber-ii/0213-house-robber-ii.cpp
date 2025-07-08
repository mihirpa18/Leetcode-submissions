class Solution {
public:
    int help(vector<int>&nums){
        if(nums.size()==1) return nums[0];
        int prev2=nums[0];
        int prev=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            int pick=nums[i]+prev2;
            int notPick=prev;
            int curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
        }

        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp2.push_back(nums[i]);
            if(i!=n-1) temp1.push_back(nums[i]);
        }

        return max(help(temp1),help(temp2));

    }
};