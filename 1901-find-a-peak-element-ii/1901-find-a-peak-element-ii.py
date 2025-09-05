class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        l=0
        h=len(mat[0])-1

        n=len(mat)
        def maxEle(col):
            maxi=-1e9
            res=-1
            for i in range(n):
                if mat[i][col]>maxi:
                    maxi=mat[i][col]
                    res=i
            return res

        while l<=h:
            mid=(l+h)//2
            maxi=maxEle(mid)

            left=mat[maxi][mid-1] if mid-1>=0 else -1
            r=mat[maxi][mid+1] if mid+1<len(mat[0]) else -1

            if mat[maxi][mid]>left and mat[maxi][mid]>r:
                return [maxi,mid]
            
            elif mat[maxi][mid]<left:
                h=mid-1
            else:
                l=mid+1
        

        return [-1,-1]