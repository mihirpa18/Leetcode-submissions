class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        diffArray = [0]*(n+2)

        for a in bookings:
            diffArray[a[0]] += a[2]
            diffArray[a[1]+1] -= a[2]
        

        arr = []

        cumSum = 0
        for i in range(1,n+1):
            cumSum += diffArray[i]
            arr.append(cumSum)

        return arr
