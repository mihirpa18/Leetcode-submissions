class Solution {
    int n;
    int mod = 1e9+7;
    pair<int,int> solve(int i, int j, vector<string>& board,vector<vector<pair<int,int>>>&dp){
        if(board[i][j] == 'E') return {0,1};
        if(board[i][j] == 'X') return {0,0};

        if(dp[i][j] != make_pair(-1,-1)) return dp[i][j];

        int upScore=0,leftScore=0,diagScore=0;
        int upPath=0,leftPath=0,diagPath=0;

        if((i-1)>=0){
            auto ans = solve(i-1,j,board,dp);
            upScore = ans.first;
            upPath = ans.second;

            if(board[i][j] != 'S' && upPath>0){
                upScore += board[i][j]-'0';
            }
        }
        if((j-1)>=0){
            auto ans = solve(i,j-1,board,dp);
            leftScore = ans.first;
            leftPath = ans.second;

            if(board[i][j] != 'S' && leftPath>0){
                leftScore += board[i][j]-'0';
            }
        }
        if((i-1)>=0 && (j-1)>=0){
            auto ans = solve(i-1,j-1,board,dp);
            diagScore = ans.first;
            diagPath = ans.second;

            if(board[i][j] != 'S' && diagPath>0){
                diagScore += board[i][j]-'0';
            }
        }

        int bestScore,bestPath;
        if(upScore == leftScore && leftScore == diagScore){
            bestScore=upScore;
            bestPath=leftPath+upPath+diagPath;
        }
        else if(upScore == leftScore){
            bestScore = upScore;
            bestPath=leftPath+upPath;

            if(diagScore>bestScore || (diagScore==bestScore && diagPath>bestPath)){
                bestScore = diagScore;
                bestPath=diagPath;
            }
        }
        else if(diagScore == leftScore){
            bestScore = leftScore;
            bestPath=leftPath+diagPath;

            if(upScore>bestScore || (upScore==bestScore && upPath>bestPath)){
                bestScore = upScore;
                bestPath=upPath;
            }
        }
        else if(upScore == diagScore){
            bestScore = upScore;
            bestPath=diagPath+upPath;

            if(leftScore>bestScore || (leftScore==bestScore && leftPath>bestPath)){
                bestScore = leftScore;
                bestPath=leftPath;
            }
        }
        else{
            bestScore = upScore; bestPath = upPath;
            if (leftScore > bestScore || (leftScore == bestScore && leftPath > bestPath)) {
                bestScore = leftScore; bestPath = leftPath;
            }
            if (diagScore > bestScore || (diagScore == bestScore && diagPath > bestPath)) {
                bestScore = diagScore; bestPath = diagPath;
            }
        }

        return dp[i][j]=make_pair(bestScore,bestPath%mod);
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n,{-1,-1}));

        auto res = solve(n-1,n-1,board,dp);

        return {res.first,res.second};
    }
};