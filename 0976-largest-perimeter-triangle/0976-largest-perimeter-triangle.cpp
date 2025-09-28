class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=n-3,j=n-2,k=n-1;
        while(i>=0){
            if(nums[i]+nums[j]>nums[k]){
                return nums[i]+nums[j]+nums[k];
            }
            i--,j--,k--;
        }

        return 0;
    }
};