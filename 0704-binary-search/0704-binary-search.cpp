class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size();
        int mid=(l+h)/2;
        while(l<=h){
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>target){
                h=mid-1;
                mid=(l+h)/2;
            }
            else if(nums[mid]<target){
                l=mid+1;
                mid=(l+h)/2;
            }
            else{
                return -1;
            }
        }

        return -1;
    }
};