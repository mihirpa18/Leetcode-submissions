class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int n=intervals.size();
        int ind=0;
        while(ind<n && intervals[ind][1]<newInterval[0]){
            res.push_back(intervals[ind]);
            ind++;
        }
        while(ind<n && intervals[ind][0]<=newInterval[1]){
            newInterval[0]=min(intervals[ind][0],newInterval[0]);
            newInterval[1]=max(intervals[ind][1],newInterval[1]);
            ind++;
        }    
        res.push_back(newInterval);
        for(int i=ind;i<n;i++){
            res.push_back(intervals[i]);
        }
        

        return res;
    }
};