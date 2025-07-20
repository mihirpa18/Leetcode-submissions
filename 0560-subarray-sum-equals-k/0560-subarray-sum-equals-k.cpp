class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int count=0;
        unordered_map<int,int>map;
        map[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum-k;
            if(map.find(rem)!=map.end()){
                count+=map[rem];
            }
            map[sum]++;
        }

        return count;
    }
};