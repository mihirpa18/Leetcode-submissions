class Solution {
    int n;
    int solve(vector<int>& nums, int k){
        int i=0,j=0;
        int oddC=0;
        int count = 0;
        for(int j=0;j<n;j++){
            if(nums[j]%2 == 1) oddC++;

            while(oddC > k){
                if(nums[i]%2 == 1) oddC--;
                i++;
            }

            count += (j-i+1);
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        n = nums.size();

        return solve(nums,k)-solve(nums,k-1);
    }
};