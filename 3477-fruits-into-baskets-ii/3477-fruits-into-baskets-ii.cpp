class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        vector<int>vis(n,0);
        int count=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j] && !vis[j]){
                    vis[j]=1;
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};