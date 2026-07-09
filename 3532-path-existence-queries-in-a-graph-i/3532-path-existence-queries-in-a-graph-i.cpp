class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>comp(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] > maxDiff){
                comp[i] = comp[i-1] + 1;
            }
            else{
                comp[i] = comp[i-1];
            }
        }

        vector<bool>res;
        for(auto &t : queries){
            if(comp[t[0]] == comp[t[1]]){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }

        return res;
    }
};