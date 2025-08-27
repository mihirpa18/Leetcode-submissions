class Solution:
    def decodeString(self, s: str) -> str:
        stack = []

        for i in range(len(s)):
            if s[i]!=']':
                stack.append(s[i])
            else:
                t=""
                while stack[-1]!='[':
                    t=stack.pop()+t
                stack.pop()
                
                k=""
                while stack and stack[-1].isdigit():
                    k=stack.pop()+k
                x=int(k)
                while x>0:
                    stack.append(t)
                    x=x-1

        res=""
        while len(stack)!=0:
            res=stack.pop()+res

        return res

