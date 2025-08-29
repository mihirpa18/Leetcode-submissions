class Solution:
    

    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def dfs(r,c,graph,vis:List[List[int]]):
            vis[r][c]=1
            dr=[-1,0,1,0]
            dc=[0,1,0,-1]

            for i in range(4):
                nr=dr[i]+r
                nc=dc[i]+c
                if nr<len(graph) and nr>=0 and nc>=0 and nc<len(graph[0]) and graph[nr][nc]=='O' and not vis[nr][nc]:
                    dfs(nr,nc,graph,vis)

        vis=[[0]*len(board[0]) for i in range(len(board))]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if (i==0 or i==len(board)-1 or j==0 or j==len(board[0])) and board[i][j]=='O' and not vis[i][j]:
                    dfs(i,j,board,vis)
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]=='O' and not vis[i][j]:
                    board[i][j]='X'

