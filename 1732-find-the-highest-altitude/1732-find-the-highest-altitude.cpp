class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prev = 0, curr = 0;
        int res = 0;
        for(auto &t:gain){
            curr = prev + t;
            res = max(curr,res);
            prev = curr;
        }

        return res;
    }
};