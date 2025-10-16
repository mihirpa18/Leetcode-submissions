class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=0) mp[(nums[i]%value)]++;
            else mp[(nums[i]%value+value)%value]++;
            
        }
        int i=0;
        while(!mp.empty()){
            if(mp.find(i%value)==mp.end()) return i;
            else{
                mp[i%value]--;
                if(mp[i%value]==0) mp.erase(i%value);
                i++;
            }

        }

        return i;
    }
};