class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>grid(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            if(mat[0][i]==1) grid[0][i]=1;
        }

        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(mat[i][j]==1){
                    grid[i][j]=grid[i-1][j]+1;
                }
            }
        }

        int res=0;
        for(int i=0;i<n;i++){
            stack<vector<int>>st;
            st.push({-1,-1,0}); //{height,pse,prevVal}
            for(int j=0;j<m;j++){
                while(st.top()[0]>=grid[i][j]){
                    st.pop();
                }

                int temp=grid[i][j]*(j-st.top()[1])+st.top()[2];
                st.push({grid[i][j],j,temp});
                res+=temp;
            }
        }

        return res;
    }
};