class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>>best(m,vector<int>(n,-1));
        priority_queue<tuple<int,int,int>>pq;

        int startHealth = health - grid[0][0];
        if(startHealth < 1) return false;

        pq.push({startHealth,0,0});
        best[0][0] = startHealth;

        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};

        while(!pq.empty()){
            auto [h,r,c] = pq.top();
            cout<<h<<" "<<r<<" "<<c<<endl;
            pq.pop();

            if(h < 1) continue;

            if(r == m-1 && c == n-1 && h>=1) return true;

            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n){

                    int nh = h-grid[nr][nc];
                    if(nh > best[nr][nc]){
                        best[nr][nc] = nh;
                        pq.push({nh,nr,nc}); 
                    }
                }
            }
        }

        return false;
    }
};