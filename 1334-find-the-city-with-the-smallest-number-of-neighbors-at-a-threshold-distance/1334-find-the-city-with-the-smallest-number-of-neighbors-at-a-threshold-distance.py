class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:

        dist=[[int(1e9) for _ in range(n)] for _ in range(n)]
        for i in range(n):
            dist[i][i] = 0
        for e in edges:
            dist[e[0]][e[1]]=e[2]
            dist[e[1]][e[0]]=e[2]

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j])

        res=-1
        tempC=1e9
        for i in range(n):
            c=0
            for j in range(n):
                # print(dist[i][j])
                if dist[i][j]<=distanceThreshold:
                    c+=1
            # print(c)
            if c<=tempC:
                tempC=c
                res=i

        return res