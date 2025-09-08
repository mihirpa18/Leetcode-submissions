class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        a=1
        b=n-1
        while a<=b:
            ta = int(a)
            tb=int(b)
            print(ta,tb)
            checkB=True
            while tb>0:
                temp=tb%10
                print(temp)
                if temp==0:
                    checkB=False
                    break
                tb//=10
            if not checkB:
                b-=1
                a+=1
            checkA=True
            while ta>0:
                temp=ta%10
                if temp==0:
                    checkA=False
                    break
                ta//=10
            if not checkA:
                b-=1
                a+=1
            print(checkA)
            print(checkB)
            if checkA and checkB:
                return [a,b]
        
        return [a,b]