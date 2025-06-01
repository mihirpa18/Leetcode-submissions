class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int size=min(n,limit);
        long long count=0;
        for(int i=0;i<=size;i++){
            count+=max((min(limit,n-i)-max(0,n-i-limit))+1,0);
        }

        return count;
    }
};