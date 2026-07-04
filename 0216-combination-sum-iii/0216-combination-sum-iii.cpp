class Solution {
void solve(int i, vector<int>&num, vector<vector<int>>&res, vector<int>&ans, int k, int n){
    if(ans.size()>k) return;
    if(n<0) return;
    if(i>9) return;
    if(n == 0 && ans.size()==k){
        res.push_back(ans);
        return;
    }
    
    ans.push_back(num[i]);
    solve(i+1,num,res,ans,k,n-num[i]);
    ans.pop_back();

    solve(i+1,num,res,ans,k,n);
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>num;
        for(int i=1;i<=9;i++){
            num.push_back(i);
        }
        vector<vector<int>>res;
        vector<int>ans;
        solve(0,num,res,ans,k,n);

        return res;
    }
};