class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ss = 0, is = 0,ie=k-1, ls = 0, il = n - 1,le=n-k;
        for (int i = 0; i < k; i++) {
            ss += cardPoints[i];
        }
        for (int i = n -k; i <n; i++) {
            ls += cardPoints[i];
            
        }
        cout<<ls<<" "<<ss<<endl;
        int res = 0;
        while (k > 0) {
            if (ls > ss) {
                res += cardPoints[il];
                ls -= cardPoints[il];
                il--;
                k--;
                if(k>0 && ie>=is){
                    ss-=cardPoints[ie];
                    ie--;
                } 
            }
            else{
                 res += cardPoints[is];
                 ss -= cardPoints[is];
                 is++;
                 k--;
                 if(k>0 && le<=il){
                    ls-=cardPoints[le];
                    le++;
                 } 
            }   
        }

        return res;
    }
};