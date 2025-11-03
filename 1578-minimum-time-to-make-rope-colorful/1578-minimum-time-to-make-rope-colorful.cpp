class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0,j=1,n=colors.size();
        int res=0;
        while(i<n && j<n){
            int maxi=neededTime[i];
            res+=maxi;
            while(colors[i]==colors[j]){
                maxi=max(maxi,neededTime[j]);
                res+=neededTime[j];
                j++;
            }
            res-=maxi;
            i=j;
            j++;
        }

        return res;
    }
};