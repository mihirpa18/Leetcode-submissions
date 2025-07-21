class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if (k == 0) return n > 0 ? nums[0] : -1;

        if (n == 1) {
            if (k % 2 == 0) return nums[0]; 
            else return -1;
        }

        if (k == 1) return n >= 2 ? nums[1] : -1;
        
        reverse(nums.begin(),nums.end());
        int maxi=0;
        int temp=k;
        while(nums.size()>0 && k>0){
            int last=nums[nums.size()-1];
            maxi=max(maxi,last);
            nums.pop_back();
            temp--;
            cout<<nums.size();
            if(temp==1){
                if(nums.size()>1 && nums[nums.size()-2]>maxi){
                    return nums[nums.size()-2];
                }
                else{
                    return maxi; 
                }
            }
            else if(nums.size()==0){
                if(temp==0) return -1;
                else if((k-n)%2==0) return maxi;
                else{
                    return maxi;
                }
            }
        }
        return maxi;
    }
};