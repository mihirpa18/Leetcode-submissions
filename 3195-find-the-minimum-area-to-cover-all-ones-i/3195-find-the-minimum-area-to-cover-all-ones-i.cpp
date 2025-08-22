class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l=INT_MAX,r=INT_MIN,t=INT_MAX,d=INT_MIN;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(j<l) l=j;
                    if(j>r) r=j;
                    if(i<t) t=i;
                    if(i>d) d=i;
                }
            }
        }
        cout<<l<<" "<<r<<" "<<t<<" "<<d<<" "<<endl;
        int len=(r-l+1);
        int wid=(d-t+1);

        return len*wid;
    }
};