class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        int res=original;
        int i=0;
        while(i<n){
            if(nums[i]==res){
                res=res*2;
                i=0;
                continue;
            }
            i++;
        }

        return res==original?original:res;
    }
};