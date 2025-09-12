class Solution:
    def doesAliceWin(self, s: str) -> bool:
        def isVowel(s):
            if s=='a' or s=='e' or s=='i' or s=='o' or s=='u':
                return True
            
            return False
        for i in range(len(s)):
            if isVowel(s[i]):
                return True
        
        return False