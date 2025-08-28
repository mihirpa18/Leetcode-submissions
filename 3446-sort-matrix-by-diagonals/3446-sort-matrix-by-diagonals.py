class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        matrix=[]
        n=len(grid)
        for k in range(len(grid)) :
            temp=[]
            i=0
            j=k
            while i<n and j<n:
                temp.append(grid[i][j])
                i=i+1
                j+=1
            temp.sort()
            i=0
            j=k
            for val in temp:
                grid[i][j]=val
                i+=1
                j+=1
        
        for k in range(len(grid)) :
            temp=[]
            i=k
            j=0
            while i<n and j<n:
                temp.append(grid[i][j])
                i=i+1
                j+=1
            temp.sort(reverse=True)
            i=k
            j=0
            for val in temp:
                grid[i][j]=val
                i+=1
                j+=1

        return grid