class Solution {
    int ROW;
    int COL;    

    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    bool dfs(vector<vector<int>>& grid,int r,int c){

        if(r<0 || r>=ROW || c<0 || c>=COL || grid[r][c]==1){
            return false;
        }

        if(r==ROW-1) return true;
        
        grid[r][c]=1;
        
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(dfs(grid,nr,nc)){
                return true;
            }
        }

        return false;
    }

    bool possible(vector<vector<int>>& cells,int &mid){
        vector<vector<int>>grid(ROW,vector<int>(COL,0));

        for(int i=0;i<=mid;i++){
            int x=cells[i][0];
            int y=cells[i][1];
            grid[x-1][y-1]=1;
        }

        for(int i=0;i<COL;i++){
            if(grid[0][i]==0 && dfs(grid,0,i)){
                return true;
            }
        }

        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW=row;
        COL=col;

        int l=0,h=cells.size()-1;
        int res=0;

        while(l<=h){
            int mid=(l+h)/2;
            if(possible(cells,mid)){
                l=mid+1;
                res=l;
            }
            else h=mid-1;
        }

        return res;
    }
};