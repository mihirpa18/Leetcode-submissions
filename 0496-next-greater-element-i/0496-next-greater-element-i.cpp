class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        int m=nums1.size();
        vector<int>res(m);
        vector<int>temp(n);
        stack<int>st;
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[nums2[i]]=i;
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(st.empty()) temp[i]=-1;
            else{
                temp[i]=st.top();
            }
            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            res[i]=temp[map[nums1[i]]];
        }

        return res;
    }
};