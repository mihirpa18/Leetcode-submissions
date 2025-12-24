class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        reverse(capacity.begin(),capacity.end());
        int sum=0;
        for(auto &it:apple){
            sum+=it;
        }

        int res=0;
        for(auto &it:capacity){
            res++;
            sum-=it;
            if(sum<=0) break;
        }
        return res;
    }
};