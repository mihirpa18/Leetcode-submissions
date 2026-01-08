class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n=len(nums1)
        m=len(nums2)
        lim=float('-inf')
        dp=[[lim]*m for _ in range(n)]

        def solve(i,j):
            if i==n or j==m:
                return lim
            
            if dp[i][j]!=lim:
                return dp[i][j]
            
            take=max((nums1[i]*nums2[j])+solve(i+1,j+1),(nums1[i]*nums2[j]))

            notTake=max(solve(i+1,j),solve(i,j+1))

            dp[i][j]=max(take,notTake)

            return dp[i][j]

        return solve(0,0)