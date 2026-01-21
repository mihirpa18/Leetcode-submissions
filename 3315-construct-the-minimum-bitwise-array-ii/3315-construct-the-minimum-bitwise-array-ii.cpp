class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(auto &it:nums){
            if(it==2){
                res.push_back(-1);
                continue;
            }

            bool flag=false;
            for(int i=1;i<32;i++){
                if((it & (1<<i))>0) continue;
                
                int prev=i-1;
                int x=(it ^ (1<<prev));
                res.push_back(x);
                flag=true;
                break;
            }

            if(!flag) res.push_back(-1);

        }

        return res;
    }
};