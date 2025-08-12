class Solution {
    void neighbours(string &s,queue<string>&q,unordered_set<string>&map){
        for(int i=0;i<4;i++){
            string temp=s;
            char inc=s[i]=='9'?'0':s[i]+1;
            char dec=s[i]=='0'?'9':s[i]-1;
            s[i]=inc;
            if(map.find(s)==map.end()){
                q.push(s);
                map.insert(s);
            }
            s[i]=dec;
            if(map.find(s)==map.end()){
                q.push(s);
                map.insert(s);
            }
            s=temp;
        }
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>map;
        for(auto it:deadends){
            map.insert(it);
        }
        if(map.count(target)) return -1;
        if(map.count("0000")) return -1;

        string s="0000";
        map.insert(s);
        queue<string>q;
        q.push(s);

        int res=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string top=q.front();
                q.pop();
                if(top==target) return res;
                neighbours(top,q,map);
            }
            res++;
        }
        return -1;
    }
};