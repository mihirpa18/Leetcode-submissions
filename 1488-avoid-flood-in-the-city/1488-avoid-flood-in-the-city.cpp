class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_set<int>st;
        unordered_map<int,vector<int>>mp;
        vector<int>res;
        int n=rains.size();
        for(int i=0;i<n;i++){
            if(rains[i]!=0){
                mp[rains[i]].push_back(i);
            }
        }

        for(int i=0;i<n;i++){
            int lake=rains[i];
            if(rains[i]>0){
                mp[rains[i]].erase(mp[rains[i]].begin());

                if(st.count(lake)) return {};

                st.insert(lake);
                res.push_back(-1);

                if(!mp[lake].empty()){
                    pq.push({mp[lake][0],lake});
                }
            }
            else{
                if(!pq.empty()){
                    auto tp=pq.top();
                    res.push_back(tp.second);
                    st.erase(tp.second);
                    pq.pop();
                }
                else{
                    res.push_back(1);   
                }

            }

        }
        return res;
    }
};