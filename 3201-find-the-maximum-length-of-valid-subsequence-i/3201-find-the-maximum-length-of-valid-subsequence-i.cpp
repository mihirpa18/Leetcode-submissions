class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int even=0;
        int odd=0;
        int evodd=0;
        int odev=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) even++;
            else if(nums[i]%2!=0) odd++;
        }  
        for(int i=0;i<n-1;i++){
            if(nums[0]%2==0 && nums[i]%2!=nums[i+1]%2){
                evodd++;
            }
            else if(nums[0]%2!=0 && nums[i]%2!=nums[i+1]%2){
                odev++;
            }
        }      

        return max(max(evodd+1,odev+1),max(even,odd));
    }
};