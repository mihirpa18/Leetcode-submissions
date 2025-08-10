class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){ //increasing order from back(breaking pt)
                ind=i;
                break;
            }
        }
        if(ind==-1) return reverse(nums.begin(),nums.end());
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[ind]){ //increasing order from back(breaking pt)
                swap(nums[i],nums[ind]);
                break;
            }
        }

        reverse(nums.begin()+ind+1,nums.end());

        // next_permutation(nums.begin(),nums.end());
    }
};