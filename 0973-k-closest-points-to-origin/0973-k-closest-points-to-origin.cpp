class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<double,vector<vector<int>>>map;
        priority_queue<double,vector<double>,greater<double>>pq;
        for(auto p:points){
            double dist=((p[0]*p[0])+(p[1]*p[1]));
            pq.push(dist);
            map[dist].push_back(p);
        }
        vector<vector<int>>res;
        while(k>0 && pq.size()>0){
            int top=pq.top();
            pq.pop();
            for(auto ans:map[top]){
                res.push_back(ans);    
                k--;
            }                   
        }

        return res;
    }
};