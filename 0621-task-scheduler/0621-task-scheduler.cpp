class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>hash(26,0);
        int res=0;
        for(int i=0;i<tasks.size();i++){
            hash[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(hash[i]>0) pq.push(hash[i]);
        }

        while(!pq.empty()){
            vector<int>temp;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    int top=pq.top();
                    pq.pop();
                    top--;
                    temp.push_back(top);
                }
            }

            for(auto it:temp){
                if(it>0) pq.push(it);
            }

            if(pq.empty()){
                res+=temp.size();
            }
            else res+=n+1;
        }

        return res;
    }
};