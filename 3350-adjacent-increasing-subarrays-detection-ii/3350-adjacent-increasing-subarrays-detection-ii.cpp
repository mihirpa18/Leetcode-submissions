class Solution {
    int increasing(int &i,vector<int>&nums){
        int c=1;
        int n=nums.size();
        while(i<n-1 && nums[i]<nums[i+1]){
            c++;
            i++;
        }
        return c;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int curr=1,prev=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curr++;
            }
            else{
                prev=curr;
                curr=1;
            }

            res=max(res,curr/2);
            res=max(res,min(curr,prev));
        }
        
        return res;
    }
};