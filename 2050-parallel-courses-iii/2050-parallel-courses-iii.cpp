class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        vector<int>inDeg(n+1,0);
        vector<int>maxTime(n+1,0);

        for(auto &r : relations){
            adj[r[0]].push_back(r[1]);
            inDeg[r[1]]++;
        }

        queue<int>q;

        for(int i=1;i<=n;i++){
            if(inDeg[i] == 0){
                q.push(i);
                maxTime[i] = max(maxTime[i],time[i-1]);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto &e:adj[top]){
                inDeg[e]--;
                maxTime[e] = max(maxTime[e],maxTime[top]+time[e-1]);
                if(inDeg[e] == 0){
                    q.push(e);
                }
            }
        }

        return *max_element(begin(maxTime),end(maxTime));

    }
};