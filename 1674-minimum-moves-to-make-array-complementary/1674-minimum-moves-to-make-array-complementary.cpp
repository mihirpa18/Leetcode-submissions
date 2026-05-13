class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>diff(2*limit+2,0);
        int pairs = n/2;

        //2 changes for every pairs and since (2,2*limit) -> possible sums
        diff[2] += 2*(pairs);

        for(int i=0; i<pairs; i++){
            int x = min(nums[i], nums[n-i-1]);
            int y = max(nums[i], nums[n-i-1]);

            int sum = nums[i]+nums[n-i-1];

            //1 change for (x+1,y+limit+1)
            diff[x+1]-=1;
            diff[y+limit+1]+=1;

            //0 change for sum
            diff[sum]-=1;
            diff[sum+1]+=1;
        }    

        //in diff array we take prefix sum to get the value
        int res = INT_MAX;
        int currSum = 0;
        for(int i=2; i<=2*limit; i++){
            currSum+=diff[i];
            res = min(res,currSum);
        }

        return res;
        
    }
};