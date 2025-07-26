class Solution {
    bool partition(int i,int k,int sum,vector<int>&nums,vector<int>&vis){
        if(k==0) return true;
        if(sum==k){
            return partition(0,k-1,0,nums,vis);
        }

        for(int j=0;j<nums.size();j++){
            if(vis[j] || sum+nums[j]>k) continue;
            vis[j]=1;
            if(partition(j+1,k,sum+nums[j],nums,vis)) return true;
            vis[j]=0;
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int totSum=0;
        for(auto it:nums){
            totSum+=it;
        }
        if(totSum%k!=0) return false;

        vector<int>vis(n,0);
        return partition(0,k,0,nums,vis);
    }
};