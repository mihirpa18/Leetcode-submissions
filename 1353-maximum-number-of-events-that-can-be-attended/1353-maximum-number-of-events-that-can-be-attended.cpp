class Solution {
public:
    struct compare{
        bool operator()(const vector<int>&a,const vector<int>&b){
            return a[1]>b[1];
        }
    };
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(),events.end());

        priority_queue<vector<int>,vector<vector<int>>,compare> pq;

        int i = 0;
        int day = events[0][0];
        int res = 0;

        while(!pq.empty() || i<n){
            while(i<n && day == events[i][0]){
                pq.push({events[i][0],events[i][1]});
                i++;
            }

            if(!pq.empty()){
                if(day<=pq.top()[1]){
                    res++;
                    pq.pop();
                }
            }

            day ++;

            while(!pq.empty() && pq.top()[1]<day){
                pq.pop();
            }

        }       
        return res;
    }
};