class Solution {
    void dfs(int i,vector<vector<int>>&matrix,vector<int>&visited){
        visited[i]=1;
        for(int j=0;j<matrix.size();j++){
            if(matrix[i][j]==1 && !visited[j]){
                dfs(j,matrix,visited);
            } 
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,isConnected,visited);
            }
        }
        return count;
    }
};