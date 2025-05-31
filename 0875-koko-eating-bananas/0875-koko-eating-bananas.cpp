class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int n=piles.size();
        int r=0;
        for(auto p:piles){
            if(p>r){
                r=p;
            }
        }
        int ans=r;

        while(l<=r){
            int mid=(l+r)/2;
            long long time=0;
            for(auto p:piles){
                 time=time+ceil((double)p/mid);
            }
            
            if(time<=h){
                ans=mid;
                r=mid-1;
            }
            else if(time>h){
                l=mid+1;
            }
        }

        return ans;
    }
};