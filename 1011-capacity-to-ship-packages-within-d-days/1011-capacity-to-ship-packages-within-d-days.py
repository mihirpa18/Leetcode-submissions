class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        n=len(weights)
        l=max(weights)
        h=sum(weights)
        res=1e9
        def isPossible(cap):
            ship=1
            load=0
            for w in weights:
                if load+w>cap:
                    ship+=1
                    load=w
                else:
                    load+=w

                if(ship>days):
                     return False
            
            return True
        
        while(l<=h):
            mid=(int)((l+h)/2)

            if(isPossible(mid)):
                res=min(res,mid)
                h=mid-1
            else:
                l=mid+1

        

        return res