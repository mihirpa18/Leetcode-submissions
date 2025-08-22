class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int,vector<int>>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int res=0;
        while(1){
            int x=pq.top();
            pq.pop();
            if(x==0) break;
            int y=pq.top();
            pq.pop();
            if(y==0) break;
            
            pq.push(x-1);
            pq.push(y-1);
            res+=1;
        }

        return res;
    }
};