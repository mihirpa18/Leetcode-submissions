class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n=len(board)

        for i in range(0,n,3):
            for j in range(0,n,3):
                s=set()
                for x in range(i,i+3):
                    for y in range(j,j+3):
                        if board[x][y]==".":
                            continue
                        if board[x][y] in s: 
                            return False
                        s.add(board[x][y])


        for i in range(n):
            s=set()
            for j in range(n):
                if board[i][j]==".":
                    continue
                if board[i][j] in s:
                    return False
                s.add(board[i][j])
        
        for i in range(n):
            s=set()
            for j in range(n):
                if board[j][i]==".":
                    continue
                if board[j][i] in s:
                    return False
                s.add(board[j][i])

        return True