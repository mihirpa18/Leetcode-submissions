class Solution {
    bool isMagic(vector<vector<int>>& grid,int &row,int &col){
        vector<int>colSum(3,0),rowSum(3,0);
        vector<bool>dist(9,false);
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(grid[i][j]<1 || grid[i][j]>9) return false;
                if(dist[grid[i][j]]) return false;
                dist[grid[i][j]]=true;
            }
        }
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                rowSum[i-row]+=grid[i][j];
            }
            cout<<rowSum[i-row]<<" ";
        }
        cout<<'c'<<" ";
        for(int i=col;i<col+3;i++){
            for(int j=row;j<row+3;j++){
                colSum[i-col]+=grid[j][i];
            }
            cout<<colSum[i-col]<<" ";
        }

        int leftDiag=0,rightDiag=0;
        leftDiag+=(grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2]);
        rightDiag+=(grid[row][col+2]+grid[row+1][col+1]+grid[row+2][col]);

        if(leftDiag!=rightDiag) return false;

        if(rowSum[0]!=leftDiag || rowSum[1]!=leftDiag || rowSum[2]!=leftDiag) return false;
        if(colSum[0]!=leftDiag || colSum[1]!=leftDiag || colSum[2]!=leftDiag) return false;

        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;

        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(isMagic(grid,i,j)) res++;
            }
        }

        return res;
    }
};