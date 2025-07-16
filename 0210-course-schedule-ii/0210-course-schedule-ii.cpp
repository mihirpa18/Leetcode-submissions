class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            int top=q.front();
            res.push_back(top);
            q.pop();
            for(auto it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(res.size()==numCourses) return res;
        return {};
    }
};