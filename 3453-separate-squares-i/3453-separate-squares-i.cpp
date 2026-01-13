class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        vector<int>top;

        int maxt=0.0;
        double totalArea=0.0;
        for(auto &it:squares){
            maxt=max(maxt,it[1]+it[2]);
            totalArea+=(1.0*it[2]*it[2]);
        }

        double l=0.0;
        double h=maxt;

        double res=0.0;
        while((h-l)>1e-6){
            double mid=(l+h)/2.0;
            double areaAbove=0.0;
            for(int i=0;i<n;i++){
                double x=squares[i][0];
                double y=squares[i][1];
                double tp=squares[i][1]+squares[i][2];
                double s=squares[i][2];

                if(mid>=tp) continue;
                double height;
                if(mid<=y) height=s;
                else height=tp-mid;

                areaAbove+=(height*s);
            }

            double areaBelow=totalArea-areaAbove;
            // cout<<areaAbove<<" ";
           
            if(areaAbove>areaBelow){
                l=mid;
            }
            else h=mid;
        }

        return l;
    }
};