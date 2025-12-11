class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,int>mpx;
        unordered_map<int,int>mpy;
        unordered_map<int,vector<int>>row_cols; // buildings in each row
        unordered_map<int,vector<int>>col_rows; // buildings in each column
        
        for(auto &it:buildings){
            mpx[it[0]]++;
            mpy[it[1]]++;
            row_cols[it[0]].push_back(it[1]);
            col_rows[it[1]].push_back(it[0]);
        }
        
        vector<pair<int,int>>mp_x(n+1,{-1,-1});
        vector<pair<int,int>>mp_y(n+1,{-1,-1});

        for(auto &[row, cols]:row_cols){
            int miny = *min_element(cols.begin(), cols.end());
            int maxy = *max_element(cols.begin(), cols.end());
            mp_y[row]={miny,maxy};
        }
        
        for(auto &[col, rows]:col_rows){
            int minx = *min_element(rows.begin(), rows.end());
            int maxx = *max_element(rows.begin(), rows.end());
            mp_x[col]={minx,maxx};
        }

        int res=0;
        for(auto &it:buildings){
            int x=it[0],y=it[1];
            if(mpx[x]>=3 && mpy[y]>=3){
                if((mp_y[x].first!=y && mp_y[x].second!=y) && (mp_x[y].first!=x && mp_x[y].second!=x)){
                    res++;
                }
            }
        }

        return res;
    }
};