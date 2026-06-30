class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        res = []

        def solve(openB,closeB,s):
            if(openB == closeB and openB == n):
                res.append(s)
                return
            
            if(openB < n):
                s+='('
                solve(openB+1,closeB,s)
                s = s[:-1]
            if(closeB<openB):
                s+=')'
                solve(openB,closeB+1,s)
                s = s[:-1]
            
        solve(0,0,"")
        return res
        
            

            