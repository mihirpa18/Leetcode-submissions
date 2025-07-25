class Solution {
    void combination(int i,int target,int sum,vector<int>&num,vector<int>res,vector<vector<int>>&ans,int &n){
        if(i>=n) return;
        if(sum==target){
            ans.push_back(res);
            return;
        }
        if(sum>target) return;
        sum+=num[i];
        res.push_back(num[i]);
        combination(i,target,sum,num,res,ans,n);
        sum-=num[i];
        res.pop_back();
        combination(i+1,target,sum,num,res,ans,n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>res;
        combination(0,target,0,candidates,res,ans,n);

        return ans;
    }
};