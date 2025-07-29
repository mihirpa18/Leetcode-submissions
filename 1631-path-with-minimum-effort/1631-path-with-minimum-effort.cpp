class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int cost=top.first;
            int r=top.second.first;
            int c=top.second.second;
            if(r==n-1 && c==m-1) return cost;
            int dr[4]={-1,0,1,0};
            int dc[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int maxcost=max(cost,abs(heights[r][c]-heights[nr][nc]));
                    if(maxcost<dist[nr][nc]){
                        dist[nr][nc]=maxcost;
                        pq.push({maxcost,{nr,nc}});
                    }
                }
            }
        }

        return -1;
    }
};