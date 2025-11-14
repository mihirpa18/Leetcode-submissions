class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int maxCount = 0;
        int current = 0;

        for(int x : nums) {
            if(x == 1) {
                current++;
                maxCount = max(maxCount, current);
            } else {
                current = 0;  // reset when we hit a zero
            }
        }
        
        return maxCount;
        }
};