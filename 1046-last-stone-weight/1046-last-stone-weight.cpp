class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto stone:stones){
            pq.push(stone);
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            if(x==y) pq.pop();
            else{
                int ny=x-y;
                pq.pop();
                pq.push(ny);
            }
        }
        return pq.size()>0?pq.top():0;
    }
};