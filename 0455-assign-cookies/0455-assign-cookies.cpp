class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size(),m=s.size();
        int res=0;
        int i=0,j=0;
        while(j<m && i<n){
            if(s[j]>=g[i]){
                res++;
                i++;
                j++;
                continue;
            }
            else{
                j++;
            }
        }

        return res;
    }
};