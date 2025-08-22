class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(matrix[0][i]=='1') grid[0][i]=1;
        }

        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(matrix[i][j]=='1'){
                    grid[i][j]=grid[i-1][j]+1;
                }
            }
        }

        int res=INT_MIN;
        for(int i=0;i<n;i++){
            stack<int>st;
            for(int j=0;j<m;j++){
                while(!st.empty() && grid[i][st.top()]>grid[i][j]){
                    int elem=grid[i][st.top()];
                    // cout<<elem<<" ";
                    st.pop();
                    int next=j;
                    int prev=st.empty()?-1:st.top();

                    res=max(res,elem*(next-prev-1));
                }
               st.push(j);
            }
            while(!st.empty()){
                int elem=grid[i][st.top()];
                // if(i==2) cout<<elem<<" ";
                st.pop();
                int next=m;
                int prev=st.empty()?-1:st.top();
                // if(i==2) cout<<next<<" "<<prev<<" ";

                res=max(res,elem*(next-prev-1));
            }
        }

        return res;
        
    }
};