class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int area=0;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int ele=heights[st.top()];
                st.pop();
                int prevs=st.empty()?-1:st.top();
                int nexts=i;
                area=max(area,ele*(nexts-prevs-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nexts=n;
            int ele=heights[st.top()];
            st.pop();
            int prevs=st.empty()?-1:st.top();
            area=max(area,ele*(nexts-prevs-1));
        }

        return area;
    }
};