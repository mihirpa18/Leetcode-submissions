class Solution {
    //string to store first col possible combinations of colors
    vector<string>colState;
    int mod=1e9+7;
    vector<vector<int>>dp;

    void generateString(int i,string curr,char prev,int m){
        if(i==m){
            colState.push_back(curr);
            return;
        }
        for(auto c:{'R','B','G'}){
            if(c==prev) continue;

            generateString(i+1,curr+c,c,m);
        }
    }

    int solve(int i,int remCol,int m){
        if(remCol==0){
            return 1;
        }

        if(dp[remCol][i]!=-1) return dp[remCol][i];

        string prevCol=colState[i];
        int ways=0; 

        for(int j=0;j<colState.size();j++){
            if(j==i) continue;
            string currCol=colState[j];
            // cout<<currCol<<" ";
            bool flag=true;
            for(int k=0;k<m;k++){
                if(prevCol[k]==currCol[k]){
                    flag=false;
                    break;
                }
            }

            if(flag){
                ways=(ways+solve(j,remCol-1,m))%mod;
            }

        }

        return dp[remCol][i]=ways;
    }

public:
    int colorTheGrid(int m, int n) {
        //generate all possible first col strings
        generateString(0,"",'#',m);

        int size=colState.size();

        dp=vector<vector<int>>(n+1,vector<int>(size+1,-1));
        int res=0;
        for(int i=0;i<size;i++){
            res=(res+solve(i,n-1,m))%mod;
        }

        return res;
    }
};