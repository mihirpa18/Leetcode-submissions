class Solution {
    int n;

    // int solve(int i, vector<int>& arr,unordered_map<int,vector<int>>& mp){
    //     if(i >= n){
    //         return INT_MIN;
    //     }

    //     int front =INT_MAX,back = INT_MAX, eq =INT_MAX;
    //     if(i+1<n){
    //         front = 1 + solve(i+1,arr,mp);
    //     }
    //     if(i-1 >= 0){
    //         back = 1+ solve(i-1,arr,mp);
    //     }

    //     for(int j=1;j<mp[arr[i]].size();j++){
    //         eq = 1 + solve(mp[arr[i]][j],arr,mp);
    //     }

    //     return min(front,min(back,eq));

    // }
public:
    int minJumps(vector<int>& arr) {
        if(n == 1) return 0;
        n = arr.size(); 
        unordered_map<int,vector<int>>mp;;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        
        queue<int>q;
        vector<bool>vis(n,0);
        q.push(0);
        
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front();
                q.pop();

                if(i == n-1) return res;

                if(i-1>=0 && !vis[i-1]){
                    vis[i-1]=true;
                    q.push(i-1);
                }
                if(i+1>=0 && !vis[i+1]){
                    vis[i+1]=true;
                    q.push(i+1);
                }

                for(auto &it:mp[arr[i]]){
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }

                mp[arr[i]].clear();

            }

            res++;

        }

        return -1;
    }
};