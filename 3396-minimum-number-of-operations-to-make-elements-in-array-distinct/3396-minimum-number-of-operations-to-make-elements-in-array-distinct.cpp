class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(101,0);

        for(int i=n-1;i>=0;i--){
            temp[nums[i]]++;
            if(temp[nums[i]]>1){
                    return (i+3)/3;
            }
        }
        return 0;
    }
};