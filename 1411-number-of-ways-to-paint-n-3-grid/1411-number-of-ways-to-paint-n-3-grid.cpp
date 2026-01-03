class Solution {

public:
    int numOfWays(int n) {
        int mod=1e9+7;
        long long res=0;

        long long x=6; //(first and last column same)
        long long y=6; //first and last column different

        for(int i=2;i<=n;i++){
            long long newx=(3*x+2*y)%mod; //Can form 3 Alternating + 2 All Different patterns
            long long newy=(2*x+2*y)%mod; //Can form 2 Alternating + 2 All Different patterns
            x=newx;
            y=newy;
        }

        return (x+y)%mod;
    }
};


    // vector<string>colState;
    // int mod=1e9+7;
    // vector<vector<int>>dp;

    // void generateString(int i,string curr,char prev,int m){
    //     if(i==m){
    //         colState.push_back(curr);
    //         return;
    //     }
    //     for(auto c:{'R','B','G'}){
    //         if(c==prev) continue;

    //         generateString(i+1,curr+c,c,m);
    //     }
    // }

    // int solve(int i,int remCol,int m){
    //     if(remCol==0){
    //         return 1;
    //     }

    //     if(dp[remCol][i]!=-1) return dp[remCol][i];

    //     string prevCol=colState[i];
    //     int ways=0; 

    //     for(int j=0;j<colState.size();j++){
    //         if(j==i) continue;
    //         string currCol=colState[j];
    //         // cout<<currCol<<" ";
    //         bool flag=true;
    //         for(int k=0;k<m;k++){
    //             if(prevCol[k]==currCol[k]){
    //                 flag=false;
    //                 break;
    //             }
    //         }

    //         if(flag){
    //             ways=(ways+solve(j,remCol-1,m))%mod;
    //         }

    //     }

    //     return dp[remCol][i]=ways;
    // }
    // int numOfWays(int n) {
    //     generateString(0,"",'#',3);

    //     int size=colState.size();

    //     dp=vector<vector<int>>(n+1,vector<int>(size+1,-1));
    //     int res=0;
    //     for(int i=0;i<size;i++){
    //         res=(res+solve(i,n-1,3))%mod;
    //     }

    //     return res;
    // }