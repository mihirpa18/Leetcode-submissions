class Solution {
    typedef long long ll;
    unordered_map<string,vector<pair<string,ll>>>adj;
    unordered_set<int>len;
    vector<ll>dp=vector<ll>(10001,-1);

    ll dijkstra(string &s,string &t){
        priority_queue<pair<ll,string>,vector<pair<ll,string>>,greater<pair<ll,string>>>pq;
        unordered_map<string,ll>dist;

        dist[s]=0;
        pq.push({0,s});

        while(!pq.empty()){
            auto top=pq.top();
            ll cost=top.first;
            string node=top.second;
            pq.pop();

            // if(s==t) break;

            for(auto &it:adj[node]){
                string nn=it.first;
                ll nc=it.second;

                if(!dist.count(nn) || nc+cost<dist[nn]){
                    dist[nn]=nc+cost;
                    pq.push({dist[nn],nn});
                }
            }
        }

        return (!dist.count(t))?1e10:dist[t];
    }

    ll solve(int i,string &s,string &t){
        if(i>=s.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        ll res=1e10;
        if(s[i]==t[i]){
            res=solve(i+1,s,t);
        }

        for(auto &it:len){
            if(i+it>s.size()) continue;

            string srcsub=s.substr(i,it);
            string tarsub=t.substr(i,it);

            if(!adj.count(srcsub)) continue;

            ll dist=dijkstra(srcsub,tarsub);
            if(dist==1e10) continue;

            res=min(res,dist+solve(i+it,s,t));
        }
        

        return dp[i]=res;
    }

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n=original.size();
        for(int i=0;i<n;i++){
            adj[original[i]].push_back({changed[i],cost[i]});
        }

        for(auto &s:original){
            len.insert(s.size());
        }

        ll res= solve(0,source,target);

        return res==1e10?-1:res;
    }
};