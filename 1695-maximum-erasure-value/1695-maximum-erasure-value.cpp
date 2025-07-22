class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;

        int i=0,j=0;
        int sum=0,temp=0;
        while(i<n && j<n){
            
            map[nums[j]]++;
            while(map[nums[j]]>1){
                map[nums[i]]--;
                temp-=nums[i];
                i++;
            }
            temp+=nums[j];
            sum=max(sum,temp);
            j++;
        }

        return sum;
    }
};