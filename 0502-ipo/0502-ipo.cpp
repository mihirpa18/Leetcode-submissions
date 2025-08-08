class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>temp;

        for(int i=0;i<n;i++){
            temp.push_back({capital[i],profits[i]});
        }
        sort(temp.begin(),temp.end());
        priority_queue<int,vector<int>>pq;
        int i=0;
        while(k>0){
            while(i<n && temp[i].first<=w){
                pq.push(temp[i].second);
                i++;
            }

            if(pq.empty()) break;
            w+=pq.top();
            k--;
            pq.pop();
        }
        return w;
    }
};