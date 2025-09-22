class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        queue<int>q;
        vector<int>vis(n);
        q.push(0);
        int far=0;
        while(!q.empty()){
            int l=q.front();
            q.pop();
            int left=max(l+minJump,far);
            for(int i=left;i<=min(l+maxJump,n-1);i++){
                if(s[i]=='0' && !vis[i]){
                    if(i==n-1) return true;
                    q.push(i);
                    vis[i]=1;
                   
                }
            }
            far=min(l+maxJump,n-1);
        }
        return false;
    }
};