class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod=1e9+7;
        unordered_map<int,int>valid_i,valid_j;
        int n=nums.size();
        int res=0;

        //two possibilities for every nums,can be k(x is present before) or j(2x is present before)
        for(int i=0;i<n;i++){
            //k
            if(nums[i]%2==0 && valid_j.count(nums[i]/2)){
                res=(res+valid_j[nums[i]/2])%mod;
            } 

            //j
            valid_j[nums[i]]=(valid_j[nums[i]]+valid_i[nums[i]*2])%mod;

            valid_i[nums[i]]++;
        }
        
        return res;
    }
};
