class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        res = 0
        n = len(s)

        i = 0
        j = 0
        mp = [0]*3

        for j in range(n):
            mp[ord(s[j])-ord('a')]+=1

            while(mp[0]>0 and mp[1]>0 and mp[2]>0):
                res += n-j
                mp[ord(s[i])-ord('a')]-=1
                i+=1
            
        
        return res