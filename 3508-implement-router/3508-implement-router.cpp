class Router {
    queue<pair<pair<int,int>,int>>q;
    set<pair<pair<int,int>,int>>st;
    int size;
public:
    Router(int memoryLimit) {
        size=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        pair<pair<int,int>,int>temp;
        temp.first.first=source;
        temp.first.second=destination;
        temp.second=timestamp;
        if(st.find(temp)!=st.end()){
            return false;
        }
        if(q.size()>=size){
            auto temp=q.front();
            st.erase(temp);
            q.pop();
        }
        q.push(temp);
        st.insert(temp);
        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int>res;
        if(q.empty()){
            return res;
        }
        auto temp=q.front();
        res.push_back(temp.first.first);
        res.push_back(temp.first.second);
        res.push_back(temp.second);
        q.pop();
        st.erase(temp);
        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        vector<pair<pair<int,int>,int>>vec;
        int res=0;
        while(!q.empty()){
            auto temp=q.front();
            vec.push_back(temp);
            q.pop();
        }
        for(int i=0;i<vec.size();i++){
            int dst=vec[i].first.second;
            int time=vec[i].second;
            if(time>=startTime && time<=endTime && dst==destination){
                res++;
            }
            q.push(vec[i]);
        }

        return res;
        
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */