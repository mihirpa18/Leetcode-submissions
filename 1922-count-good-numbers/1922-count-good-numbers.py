class Solution:
    def power(self,a,b,mod):
        res = 1
        while(b):
            if(b&1):
                res = (res*a)%mod
            a = (a*a)%mod

            b>>=1
        
        return res


    def countGoodNumbers(self, n: int) -> int:
        res = 1
        mod = 10**9 + 7
        even = (n+1)//2
        odd = n//2

        return (self.power(5,even,mod)*self.power(4,odd,mod))%mod