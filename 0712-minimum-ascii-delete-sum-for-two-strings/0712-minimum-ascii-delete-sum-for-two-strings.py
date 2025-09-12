class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n=len(s1)
        m=len(s2)
        sum1=0
        sum2=0
        for k in range(n):
            sum1+=ord(s1[k])
        for k in range(m):
            sum2+=ord(s2[k])
        lcs=0
        dp=[[0]*(m+1) for i in range(n+1)]

        for i in range(1,n+1):
            for j in range(1,m+1):
                if s1[i-1]==s2[j-1]:
                    dp[i][j]=ord(s1[i-1])+dp[i-1][j-1]
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        
        lcs=dp[n][m]
        
        return sum1+sum2-(2*lcs)
       
        