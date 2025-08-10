class Solution {
    void solve(int i,vector<int>&nums,vector<int>ans,vector<vector<int>>&res){
            res.push_back(ans);
        

        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            ans.push_back(nums[j]);
            solve(j+1,nums,ans,res);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        
        sort(nums.begin(),nums.end());
        solve(0,nums,ans,res);

        return res;
    }
};