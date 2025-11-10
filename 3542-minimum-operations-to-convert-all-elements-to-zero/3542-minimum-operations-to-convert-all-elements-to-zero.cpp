class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int res=0;
        for(auto &it:nums){
            if(it==0){
                while(!st.empty()) st.pop();
                continue;
            }
            if(st.empty() || it>st.top()){
                st.push(it);
                res++;
            }
            else if(it<st.top()){
                while(!st.empty() && it<st.top()) st.pop();
                if(st.empty()){
                    st.push(it);
                    res++;
                } 
            }
        }
        return res;
    }
};