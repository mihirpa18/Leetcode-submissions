class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>grid(26,vector<int>(26,1e9));
        int n=original.size();

        for(int i=0;i<n;i++){
            int x=original[i]-'a';
            int y=changed[i]-'a';
            grid[x][y]=min(grid[x][y],cost[i]);
        }

        for(int i=0;i<26;i++){
            grid[i][i]=0;
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(grid[i][k]!=1e9 && grid[k][j]!=1e9)
                        grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
                }
            }
        }

        int m=source.size();
        long long res=0;
        for(int i=0;i<m;i++){
            if(source[i]==target[i]) continue;
            int x=source[i]-'a';
            int y=target[i]-'a';
            if(grid[x][y]==1e9) return -1;

            res+=grid[x][y];
        }

        return res;
    }
};