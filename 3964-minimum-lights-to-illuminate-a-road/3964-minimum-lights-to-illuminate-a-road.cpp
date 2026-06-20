class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<vector<int>>vis;
        for(int i=0;i<n;i++){
            if(lights[i] != 0){
                if(!vis.empty() && vis.back()[1] > max(0, i - lights[i])){
                    vis.back()[0] = min(vis.back()[0],max(0, i - lights[i]));
                    vis.back()[1] = max(vis.back()[1],min(n - 1, i + lights[i]));
                }
                else{
                    int mini = max(0, i - lights[i]) ;
                    int maxi = min(n-1, i + lights[i]) ;
                    vis.push_back({mini,maxi});
                } 
            }
        }

        int res = 0;
        int i = 0;
        for(auto & t : vis){
            cout<<t[0]<<" "<<t[1]<<endl;
            if(t[0] - i > 0){
                res += ceil((t[0]-i)/3.0);
            } 
            i = t[1]+1;
        }
        res += ceil((n-i)/3.0);
        return res;
    }
};