class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int>newInt(2);
        newInt[0]=intervals[0][0];
        newInt[1]=intervals[0][1];
        int i=0,j=0;
        vector<vector<int>>res;
        while(i<n){
            newInt[0]=intervals[i][0];
            newInt[1]=intervals[i][1];
            while(i<n-1 && newInt[1]>=intervals[i+1][0]){
                newInt[0]=min(intervals[i+1][0],newInt[0]);
                newInt[1]=max(intervals[i+1][1],newInt[1]);
                i++;
            }
            res.push_back(newInt);
            i++;
        }

        return res;
    }
};