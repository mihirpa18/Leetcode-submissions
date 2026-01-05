class Solution:
    def maxMatrixSum(self, mat: List[List[int]]) -> int:
        n=len(mat)
        totSum=0
        neg=0
        minAbsVal=float('inf')
        for i in range(n):
            for j in range(n):
                totSum+=abs(mat[i][j])
                print(abs(mat[i][j]))
                if(mat[i][j]<0):
                    neg+=1
                minAbsVal=min(minAbsVal,abs(mat[i][j]))
        print(totSum)
        print(neg)
        print(minAbsVal)
                
        if(neg%2!=0):
            totSum-=2*minAbsVal

        return totSum