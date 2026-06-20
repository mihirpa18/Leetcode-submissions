class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        unordered_map<int,vector<int>>mp;
        vector<int>vis(n,0);
        vector<double>time(n,0);

        for(auto &t : edges){
            mp[t[0]].push_back(t[1]);
            vis[t[0]] = 1;
        }

        for(int i=n-1;i>=0;i--){
            time[i] = baseTime[i];
            if(vis[i] != 0){
                double earliest = 1e9;
                double latest = -1e9;
                double ownDuration = 0;
                for(auto &t:mp[i]){
                    earliest = min(earliest,time[t]);
                    latest = max(latest,time[t]);
                }
                if(earliest != 1e9 && latest!=-1e9) ownDuration = (latest - earliest) + baseTime[i];
                else ownDuration = baseTime[i];
                time[i] = (ownDuration + latest);
            }
        }
        

        return time[0];
    }
};