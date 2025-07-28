class Solution {
    int maxi=0;
    void maxOr(int i,int val,vector<int>&nums,vector<int>&res,vector<vector<int>>&ans){
        if(i>=nums.size()) return;
        if((val | nums[i]) == maxi){
            ans.push_back(res);
        }
        else if( (val | nums[i]) > maxi){
            ans.clear();
            maxi=(val | nums[i]);
            ans.push_back(res);
        }

        res.push_back(nums[i]);
        maxOr(i+1,(val | nums[i]),nums,res,ans);
        res.pop_back();
        maxOr(i+1,val,nums,res,ans);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int>res;
        vector<vector<int>>ans;

        maxOr(0,0,nums,res,ans);

        return ans.size();
    }
};