class Solution {
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int count=0;
        int end=intervals[0][1];
        for(int i=0;i<n-1;i++){  
            if(end>intervals[i+1][0]){
                count++;
            }
            else end=intervals[i+1][1];
        }
        
        return count;
    }
};