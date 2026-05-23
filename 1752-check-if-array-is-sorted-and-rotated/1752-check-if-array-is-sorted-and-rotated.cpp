class Solution {
public:
    bool check(vector<int>& nums) {
        int n= nums.size();
        bool flag = false;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[(i-1)]){
                if(flag) return false;
                if(nums[n-1] > nums[0]) return false;
                flag = true;
                if(nums[(i-1)] < nums[(i+1)%n]) return false;
            }
        }

        return true;
    }
};