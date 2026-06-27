class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        diffArray = [0]*1001

        for a in trips:
            diffArray[a[1]] += a[0]
            diffArray[a[2]] -= a[0]
        
        cumSum = 0
        for d in diffArray:
            cumSum += d
            if(cumSum>capacity):
                return False
        
        return True