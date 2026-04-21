class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)

        parent = list(range(n))

        def find(x):
            if(parent[x] == x):
                return x
            
            parent[x] = find(parent[x])
            return parent[x]
        
        def union(u,v):
            pu,pv = find(u), find(v)

            if(pu != pv):
                parent[pv] = pu
            
        for u,v in allowedSwaps:
            union(u,v)
        
        group = defaultdict(list)

        for i in range(n):
            group[find(i)].append(i)
        
        res = 0 
        
        for it in group.values():
            count = Counter()

            for i in it:
                count[source[i]] +=1
            
            for i in it:
                if(count[target[i]]>0):
                    count[target[i]] -= 1
                else:
                    res+=1

        return res
        