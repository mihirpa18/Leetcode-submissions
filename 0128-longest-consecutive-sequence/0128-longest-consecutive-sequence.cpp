class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int len=1;
         
        for(auto it:s){
            if(s.find(it-1)==s.end()){
                int currele=it;
                int count=1;
                while(s.find(currele+1)!=s.end()){
                    currele+=1;
                    count++;
                }
                len=max(len,count);
            }
        }

        return len;
    }
};